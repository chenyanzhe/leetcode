#include "catch.hpp"

#include "SearchInRotatedSortedArray.hpp"

TEST_CASE("Search in Rotated Sorted Array") {
    SearchInRotatedSortedArray s;
    SECTION("Normal tests") {
        vector<int> nums{4, 5, 6, 7, 0, 1, 2};

        for (int i = 0; i < nums.size(); i++)
            REQUIRE(s.search(nums, nums[i]) == i);

        REQUIRE(s.search(nums, 3) == -1);
    }
    SECTION("Ascending nums") {
        vector<int> nums{0, 1, 2, 4, 5, 6, 7};

        for (int i = 0; i < nums.size(); i++)
            REQUIRE(s.search(nums, nums[i]) == i);

        REQUIRE(s.search(nums, 3) == -1);
    }
}
