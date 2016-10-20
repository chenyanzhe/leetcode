#include "catch.hpp"

#include "MaximumSizeSubarraySumEqualsK.hpp"

TEST_CASE("Maximum Size Subarray Sum Equals k") {
    MaximumSizeSubarraySumEqualsK s;
    SECTION("Sample tests") {
        vector<int> nums1{1, -1, 5, -2, 3};
        REQUIRE(s.maxSubArrayLen(nums1, 3) == 4);
        vector<int> nums2{-2, -1, 2, 1};
        REQUIRE(s.maxSubArrayLen(nums2, 1) == 2);
    }
}
