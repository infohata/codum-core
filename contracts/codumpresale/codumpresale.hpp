#pragma once

#include <eosiolib/eosio.hpp>
#include <eosiolib/types.hpp>
#include <eosiolib/asset.hpp>

#include <string>

using std::string;
using namespace eosio;

const account_name tokencontract = N(codumtestnet);


class codumpresale : public contract
{
public:
  codumpresale(account_name self) : contract(self) {}

  /// @abi action
  void apply(const account_name contributor, const bool acceptedterms);

  /// @abi action
  void approve(const account_name contributor);

  /// @abi action
  void buycodum(const account_name contributor,
                const uint8_t network,
                const asset& quantity,
                const string& memo);

  /// @abi action
  void validate(const uint64_t id, const string& memo, const string& transaction);

  inline int64_t get_bonus_state(const uint8_t stage) const;
  inline int64_t get_sale_state(const asset& cap) const;

  inline bool is_contributor_approved(const account_name contributor) const;


  const time start = 1532433600; // Tue Jul 24 2018 12:00:00 GMT+0000
  const time end = 1537790400;   // Tue Sep 24 2018 12:00:00 GMT+0000

  const int64_t softcap_i = 38400000000;
  const int64_t hardcap_i = 192000000000;

  const asset softcap = asset(softcap_i, S(4, CODUM));
  const asset hardcap = asset(hardcap_i, S(4, CODUM));

  const int64_t bonus[2] = { 50, 25 };
  const asset bonus_thr[2] = { asset(19200000000, S(4, CODUM)), asset(38400000000, S(4, CODUM)) };

private:
  /// @abi table whitelist i64
  struct whitelist
  {
    account_name contributor;
    bool acceptedterms;
    time approved;

    uint64_t primary_key() const { return contributor; }

    EOSLIB_SERIALIZE(whitelist, (contributor)(acceptedterms)(approved))
  };

  typedef eosio::multi_index<N(whitelist), whitelist> whitelists;

  // @abi table contribution i64
  struct contribution
  {
    uint64_t id;
    account_name contributor;
    uint8_t network;
    int32_t rate;
    asset quantity;
    string memo;
    string transaction;
    time datetime;
    time validated;
    asset codum_dist;
    asset codum_bonus;
    time distributed;
    string distrib_tx;
    asset refund;
    time refunded;
    string refund_tx;

    uint64_t primary_key() const { return id; }
    account_name get_contributor() const { return contributor; }
    uint64_t get_datetime() const { return datetime; }

    // uint256_t get_memo() const {
    //   checksum256 hash;
    //   // sha256()
    //   return hash;
    // }

    EOSLIB_SERIALIZE(contribution, (id)(contributor)(network)(rate)
                                   (quantity)(memo)(transaction)(datetime)
                                   (validated)(codum_dist)(codum_bonus)
                                   (distributed)(distrib_tx)(refund)
                                   (refunded)(refund_tx))
  };

  typedef eosio::multi_index<N(contribution), contribution,
                             indexed_by<N(contributor),
                                        const_mem_fun<contribution, uint64_t, &contribution::get_contributor>>,
                             // indexed_by<N(memo),
                             //            const_mem_fun<contribution, uint256_t, &contribution::get_memo>>,
                             indexed_by<N(datetime),
                                        const_mem_fun<contribution, uint64_t, &contribution::get_datetime>>>
      contributions;
}; // class codumpresale.
