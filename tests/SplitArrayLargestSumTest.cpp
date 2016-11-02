#include "catch.hpp"

#include "SplitArrayLargestSum.hpp"

TEST_CASE("Split Array Largest Sum") {
    SplitArrayLargestSum s;
    SECTION("Sample test") {
        vector<int> nums{7, 2, 5, 10, 8};
        int m = 2;
        REQUIRE(s.splitArray(nums, m) == 18);
    }
}
