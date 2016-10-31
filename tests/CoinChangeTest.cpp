#include "catch.hpp"

#include "CoinChange.hpp"

TEST_CASE("Coin Change") {
    CoinChange s;
    SECTION("Sample tests") {
        vector<int> coins1{1, 2, 5};
        int amount1 = 11;
        REQUIRE(s.coinChange(coins1, amount1) == 3);

        vector<int> coins2{2};
        int amount2 = 3;
        REQUIRE(s.coinChange(coins2, amount2) == -1);
    }
}
