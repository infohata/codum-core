#include "codumpresale.hpp"

#include <../codum.token/codum.token.hpp>

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

    token::exrates exrate_table(tokencontract, tokencontract); // TODO: abstract to configurable const on the top of .hpp;
    auto rt = exrate_table.find(network);
    eosio_assert(rt != exrate_table.end(), "no such network in codum.token exrates table");

    ct.rate = rt->rate;
    ct.codum_dist = asset(ct.quantity.amount * ct.rate / 10000, S(4,CODUM));

    // if (network == NETWORK_EOS) {

      // action(
      //   { contributor, N(active) },
      //   tokencontract, N(transfer),
      //   std::make_tuple(contributor, _self, quantity, ct.memo)
      // ).send();

      // ct.validated = now();
    // }
  });
}

EOSIO_ABI(codumpresale, (apply)(approve)(buycodum))
