#include "catch.hpp"

#include "TargetSum.hpp"

TEST_CASE("Target Sum") {
    TargetSum s;
    SECTION("Sample test") {
        vector<int> nums {1, 1, 1, 1, 1};
        int S = 3;
        REQUIRE(s.findTargetSumWays(nums, S) == 5);
    }

    SECTION("Corner cases") {
        vector<int> nums1 {1, 0};
        int S1 = 1;
        REQUIRE(s.findTargetSumWays(nums1, S1) == 2);

        vector<int> nums2 {0, 0};
        int S2 = 0;
        REQUIRE(s.findTargetSumWays(nums2, S2) == 4);
    }
}
