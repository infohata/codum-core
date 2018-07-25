# PREPARATION

## Launch token
* create account for token contract, example: `codumreserve`, with at least 400KiB of RAM, stake 5 EOS on bandwidth, 15 EOS on CPU
* compile ABI, WAST and WASM for token, set contract:
```
cd contracts/codum.token
eosiocpp -g codum.token.abi codum.token.hpp
eosiocpp -o codum.token.wast codum.token.cpp
cleos set contract codumreserve ./ codum.token.wast codum.token.abi -p codumreserve
```
* create token, `cleos push action codumreserve create '["codumreserve", "428000000.0000 CODUM"]' -p codumreserve`

## Launch presale
* create account for presale contract, example: `codumpresale`, with at least 400KiB of RAM, stake 5 EOS on bandwidth, 15 EOS on CPU
* set `codumpresale@eosio.code` permission to `codumpresale@active`: `cleos set account permission codumpresale active '{"threshold": 1,"keys": [{"key": "CURRENT_PUBLIC_KEY_for_codumpresale@active","weight": 1}],"accounts": [{"permission":{"actor": "codumpresale","permission":"eosio.code"},"weight":1}]}' owner -p codumpresale`
* in `codumpresale.hpp` adjust configurable constants:
```cpp
  const time start = 1532433600; // Tue Jul 24 2018 12:00:00 GMT+0000 //1532433600
  const time end = 1537790400;   // Tue Sep 24 2018 12:00:00 GMT+0000 //1537790400

  const uint64_t softcap_i = 38400000000;
  const uint64_t hardcap_i = 192000000000;

  const asset softcap = asset(softcap_i, S(4, CODUM));
  const asset hardcap = asset(hardcap_i, S(4, CODUM));

  const uint8_t bonus[2] = {50, 25};
  const asset bonus_thr[2] = {asset(19200000000, S(4, CODUM)), asset(38400000000, S(4, CODUM))};

  const account_name tokencontract = N(codumreserve);
```
* compile ABI, WAST and WASM for token, set contract:
```
cd contracts/codumpresale
eosiocpp -g codumpresale.abi codumpresale.hpp
eosiocpp -o codumpresale.wast codumpresale.cpp
cleos set contract codumpresale ./ codumpresale.wast codumpresale.abi -p codumpresale
```
* issue tokens to self: `cleos push action codumreserve issue '["codumpresale", "20640000.0000 CODUM", "for round A fundraising distribution"]' -p codumreserve`
* set self as active distributor: `cleos push action codumreserve setdistrib '["0.0000 CODUM", "codumpresale"]' -p codumreserve`
* set rates, `cleos push action codumreserve updaterate '[0, 580000]" -p codumreserve` is for example for EOS, 1 = EUR, 2 = USD, 3 = ETH. Set rates for all networks. 
P.S. Due to `uint32_t` limitation max rate is capped at 429496.7295, beware selling for bitcoin once it moons.

# TEST CASE

We assume user is `codumjungles`
* apply as user: `cleos push action codumpresale apply '["codumjungles", 1] -p codumjungles`
* approve user in whitelist: `cleos push action codumpresale approve '["codumjungles"]' -p codumreserve`
* buy some codum as user: `cleos push action codumpresale buycodum '["codumjungles", 0, "1000.0000 EOS", "testmemo"]' -p codumjungles`
* transfer some EOS as user: `cleos transfer codumjungles codumpresale "1000.0000 EOS" "testmemo" -p codumjungles`
* check the entry in contributions table, you need ID: `cleos get table codumpresale codumpresale contribution --index 2 --key-type name -L "codumjungles" -U "codumjunglet"`
* before transaction is validated, you can delete it with `deletetx` action, id is the argument.
* validate transaction: `cleos push action codumpresale validate '[0, "testmemo", ""]' -p codumpresale`
* once softcap is reached, you can distribute: `cleos push action codumpresale distribute '[0]' -p codumpresale`
* refund is done by `cleos push action codumpresale refund '[0, ""]' -p codumpresale`
* once all tokens are distributed and all EOS/money refunded for oversale, or softcap not reached before the `end`, you can do finalization.

