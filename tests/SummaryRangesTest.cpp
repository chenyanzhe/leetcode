#include "catch.hpp"

#include "SummaryRanges.hpp"

TEST_CASE("Summary Ranges")
{
  SummaryRanges s;
  SECTION("Sample test") {
    vector<int> nums {0, 1, 2, 4, 5, 7};
    vector<string> expected {"0->2", "4->5", "7"};
    vector<string> result = s.summaryRanges(nums);
    REQUIRE(expected == result);
  }
}
