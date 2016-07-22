#include "catch.hpp"

#include "SearchInsertPosition.hpp"

TEST_CASE("Search Insert Position") {
    SearchInsertPosition s;
    SECTION("Sample tests") {
        vector<int> nums{1, 3, 5, 6};
        REQUIRE(s.searchInsert(nums, 5) == 2);
        REQUIRE(s.searchInsert(nums, 2) == 1);
        REQUIRE(s.searchInsert(nums, 7) == 4);
        REQUIRE(s.searchInsert(nums, 0) == 0);
    }
    SECTION("Empty vector") {
        vector<int> nums;
        REQUIRE(s.searchInsert(nums, 3) == 0);
    }
    SECTION("Single element") {
        vector<int> nums{1};
        REQUIRE(s.searchInsert(nums, 0) == 0);
        REQUIRE(s.searchInsert(nums, 3) == 1);
    }
}
