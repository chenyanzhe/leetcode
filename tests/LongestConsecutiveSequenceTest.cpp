#include "catch.hpp"

#include "LongestConsecutiveSequence.hpp"

TEST_CASE("Longest Consecutive Sequence") {
    LongestConsecutiveSequence s;
    SECTION("Sample test") {
        vector<int> nums{100, 4, 200, 1, 3, 2};
        REQUIRE(s.longestConsecutive(nums) == 4);
    }
}
