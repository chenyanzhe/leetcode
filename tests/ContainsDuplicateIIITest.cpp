#include "catch.hpp"

#include "ContainsDuplicateIII.hpp"

TEST_CASE("Contains Duplicate III") {
    ContainsDuplicateIII s;

    SECTION("Sample test") {
        vector<int> nums {1, 0, -1, 3, -2, 2};
        REQUIRE_FALSE(s.containsNearbyAlmostDuplicate(nums, 1, 0));
    }

    SECTION("Overflow test") {
        vector<int> nums {0, 2147483647};
        REQUIRE(s.containsNearbyAlmostDuplicate(nums, 1, 2147483647));
    }
}