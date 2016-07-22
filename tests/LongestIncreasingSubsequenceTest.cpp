#include "catch.hpp"

#include "LongestIncreasingSubsequence.hpp"

TEST_CASE("Longest Increasing Subsequence") {
    LongestIncreasingSubsequence s;
    SECTION("Sample test") {
        vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
        REQUIRE(s.lengthOfLIS(nums) == 4);
    }
    SECTION("Non increasing sequence") {
        vector<int> nums{2, 2};
        REQUIRE(s.lengthOfLIS(nums) == 1);
    }
}
