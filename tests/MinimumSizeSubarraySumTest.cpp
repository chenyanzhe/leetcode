#include "catch.hpp"

#include "MinimumSizeSubarraySum.hpp"

TEST_CASE("Minimum Size Subarray Sum") {
    MinimumSizeSubarraySum s;
    SECTION("Sample test") {
        vector<int> nums{2, 3, 1, 2, 4, 3};
        int target = 7;
        REQUIRE(s.minSubArrayLen(target, nums) == 2);
    }
}
