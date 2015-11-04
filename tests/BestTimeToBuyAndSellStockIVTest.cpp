#include "catch.hpp"

#include "BestTimeToBuyAndSellStockIV.hpp"

TEST_CASE("Best Time to Buy and Sell Stock IV") {
    BestTimeToBuyAndSellStockIV s;

    SECTION("Sample test") {
        vector<int> prices {10, 11, 7, 10, 6};
        REQUIRE(s.maxProfit(1, prices) == 3);
        REQUIRE(s.maxProfit(2, prices) == 4);
    }
}
