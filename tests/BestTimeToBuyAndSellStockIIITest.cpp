#include "catch.hpp"

#include "BestTimeToBuyAndSellStockIII.hpp"

TEST_CASE("Best Time to Buy and Sell Stock III")
{
  BestTimeToBuyAndSellStockIII s;
  SECTION("Normal test") {
    vector<int> prices {10, 11, 7, 10, 6};
    // buy at 10 and sell at 11, earn 1
    // buy at 7 and sell at 10, earn 3
    REQUIRE(s.maxProfit(prices) == 4);
  }
}
