#include "codumpresale.hpp"

#include <../codum.token/codum.token.hpp>

int64_t codumpresale::get_bonus_state(const uint8_t stage) const
{
  asset sum = bonus_thr[stage];

  contributions contribution_table(_self, _self);
  for (auto ct = contribution_table.begin(); ct != contribution_table.end(); ct++) {
    if (ct->validated > 0) {
      sum -= ct->codum_dist;
    }
  }

  return sum.amount;
}

int64_t codumpresale::get_sale_state(const asset& cap) const
{
  asset sum = cap;

  contributions contribution_table(_self, _self);

  if (cap == softcap) {
    for (auto ct = contribution_table.begin(); ct != contribution_table.end(); ct++) {
      if (ct->validated > 0) {
        sum -= ct->codum_dist;
      }
    }
  } else {
    for (auto ct = contribution_table.begin(); ct != contribution_table.end(); ct++) {
      if (ct->distributed > 0) {
        sum -= ct->codum_dist;
      }
    }
  }

  return sum.amount;
}

bool codumpresale::is_contributor_approved(const account_name contributor) const
{
  whitelists whitelist_table(_self, _self);
  auto itr = whitelist_table.find(contributor);
  if (itr != whitelist_table.end() && itr->acceptedterms && itr->approved > 0) {
    return true;
  }
  return false;
}

void codumpresale::apply(const account_name contributor,
                         const bool acceptedterms)
{
  require_auth(contributor);

  whitelists whitelist_table(_self, _self);
  auto itr = whitelist_table.find(contributor);
  if (itr == whitelist_table.end()) {
    // create
    whitelist_table.emplace(_self, [&](auto &wt) {
      wt.contributor = contributor;
      wt.acceptedterms = acceptedterms;
      wt.approved = 0;
    });
  } else {
    // update
    whitelist_table.modify(itr, _self, [&](auto &wt) {
      wt.contributor = contributor;
      wt.acceptedterms = acceptedterms;
    });
  }
}

void codumpresale::approve(const account_name contributor)
{
  require_auth(_self);
  eosio_assert(is_account(contributor), "contributor account does not exist");

  whitelists whitelist_table(_self, _self);
  auto itr = whitelist_table.find(contributor);

  eosio_assert(itr != whitelist_table.end(), "there is no such contributor in whitelist");
  eosio_assert(itr->acceptedterms, "contributor have not accepted terms");

  whitelist_table.modify(itr, _self, [&](auto &wt) {
    wt.approved = now();
  });
}

void codumpresale::buycodum(const account_name contributor,
                            const uint8_t network,
                            const asset& quantity,
                            const string& memo)
{
  require_auth(contributor);
  eosio_assert(get_sale_state(hardcap) > 0, "hard cap reached");
  eosio_assert(is_contributor_approved(contributor), "please wait while we approve your participation");

  contributions contribution_table(_self, _self);

  contribution_table.emplace(_self, [&](auto &ct) {
    ct.id = contribution_table.available_primary_key();
    ct.contributor = contributor;
    ct.network = network;
    ct.quantity = quantity;
    ct.datetime = now();
    ct.memo = memo;
    ct.distributed = 0;
    ct.refunded = 0;

    token::exrates exrate_table(tokencontract, tokencontract); // TODO: abstract to configurable const on the top of .hpp;
    auto rt = exrate_table.find(network);
    eosio_assert(rt != exrate_table.end(), "no such network in codum.token exrates table");

    ct.rate = rt->rate;
    ct.codum_dist = asset(ct.quantity.amount * ct.rate / 10000, S(4,CODUM));
    ct.codum_bonus = asset(0, S(4,CODUM));

    // if (network == NETWORK_EOS) {
      // action(
      //   { contributor, N(active) },
      //   tokencontract, N(transfer),
      //   std::make_tuple(contributor, _self, quantity, ct.memo)
      // ).send();
      // ct.validated = now();
    // }
}

void codumpresale::validate(const uint64_t id, const string& memo, const string& transaction)
{
  require_auth(_self);

  contributions contribution_table(_self, _self);
  auto itr = contribution_table.find(id);
  eosio_assert(itr != contribution_table.end(), "there is no contribution with this id");

  contribution_table.modify(itr, _self, [&](auto &vt) {
    eosio_assert(is_contributor_approved(vt.contributor), "please wait while we approve your participation");
    eosio_assert(memo == vt.memo, "transaction memo mismatch");
    eosio_assert(start < vt.datetime && end > vt.datetime, "date of the transaction outside sale date and time bounds");

    vt.validated = now();
    vt.transaction = transaction;

    const uint8_t stages_count = 2;

    for (uint8_t stage = 0;
         vt.codum_bonus.amount == 0 && get_bonus_state(stage) > 0 && stage < stages_count;
         stage++)
    {
      auto codum_bonus = vt.codum_dist.amount * bonus[stage] / 100;

      if (codum_bonus <= get_bonus_state(stage)) {
        vt.codum_bonus.amount = codum_bonus;
      } else {
        vt.codum_bonus.amount = get_bonus_state(stage);

        if (stage < stages_count - 1) {
          vt.codum_bonus.amount += (vt.codum_dist.amount - vt.codum_bonus.amount * 100 / bonus[stage]) * bonus[stage+1] / 100;
        }
      }
    }
  });
}

void codumpresale::distribute_sale_tokens_by_tx(const uint64_t id)
{
  require_auth(_self);
  eosio_assert(get_sale_state(softcap) < 0, "cannot distribute tokens before reaching soft cap");

  contributions contribution_table(_self, _self);
  auto itr = contribution_table.find(id);
  eosio_assert(itr != contribution_table.end(), "there is no contribution with this id");

  contribution_table.modify(itr, _self, [&](auto &dt) {
    eosio_assert(dt.validated > 0, "contribution is not validated");
    eosio_assert(dt.refunded == 0, "contribution is refunded");

    auto hardcapLeft = get_sale_state(hardcap);

    if (hardcapLeft > 0) {
      auto dc = asset(0, S(4, CODUM));

      if (hardcapLeft < dt.codum_dist.amount) {
        dc.amount = hardcapLeft;
        dt.refund = dt.quantity - (dt.codum_dist - dc) / dt.rate;
      } else {
        dc = dt.codum_dist + dt.codum_bonus;
      }

      action(
        { _self, N(active) },
        tokencontract, N(distribsale),
        std::make_tuple(_self, dt.contributor, dc, "codum private sale: " + dt.memo)
      ).send();

      dt.distributed = now(); 
    } else {
      dt.refund = dt.codum_dist / dt.rate;
      dt.distrib_tx = "";
    }

  });
}

void codumpresale::distribute()
{
  require_auth(_self);
  eosio_assert(get_sale_state(softcap) < 0, "cannot distribute tokens before reaching soft cap");

  contributions contribution_table(_self, _self);
  auto datetimeIndex = contribution_table.get_index<N(datetime)>();

  for (const auto& dt: datetimeIndex) {
    if (dt.validated > 0 && dt.distributed == 0) {
      distribute_sale_tokens_by_tx(dt.id);
    }
  }
}

EOSIO_ABI(codumpresale, (apply)(approve)(buycodum)(validate)(distribute))
