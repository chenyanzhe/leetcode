#include "catch.hpp"

#include "MinimumSizeSubarraySum.hpp"

TEST_CASE("Minimum Size Subarray Sum") {
    MinimumSizeSubarraySum s;
    SECTION("Sample test") {
        vector<int> nums{2, 3, 1, 2, 4, 3};
        int target = 7;
        REQUIRE(s.minSubArrayLen(target, nums) == 2);
    }
    SECTION("All sum up") {
        vector<int> nums{1, 2, 3, 4, 5};
        int target = 15;
        REQUIRE(s.minSubArrayLen(target, nums) == 5);
    }
    SECTION("Non-exist") {
        vector<int> nums{1, 1};
        int target = 3;
        REQUIRE(s.minSubArrayLen(target, nums) == 0);
    }
}
