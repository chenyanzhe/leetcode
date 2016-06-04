#include "catch.hpp"

#include "CoinChange.hpp"

TEST_CASE("Coin Change")
{
  CoinChange s;
  SECTION("Sample test") {
    vector<int> coins {1, 2, 5};
    int amount = 11;
    REQUIRE(s.coinChange(coins, amount) == 3);
  }
}
