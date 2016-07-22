#include "catch.hpp"

#include "BestTimeToBuyAndSellStockWithCooldown.hpp"

TEST_CASE("Best Time to Buy and Sell Stock with Cooldown") {
    BestTimeToBuyAndSellStockWithCooldown s;
    SECTION("Sample tests") {
        vector<int> prices1{1, 2, 3, 0, 2};
        REQUIRE(s.maxProfit(prices1) == 3);
        vector<int> prices2{6, 1, 3, 2, 4, 7};
        REQUIRE(s.maxProfit(prices2) == 6);
    }
}
