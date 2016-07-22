#include "catch.hpp"

#include "RemoveDuplicatesFromSortedArray.hpp"

TEST_CASE("Remove Duplicates From Sorted Array") {
    RemoveDuplicatesFromSortedArray s;
    SECTION("Sample test") {
        vector<int> nums{1, 1, 2};
        vector<int> expected{1, 2};
        REQUIRE(s.removeDuplicates(nums) == 2);

        for (int i = 0; i < 2; i++)
            REQUIRE(nums[i] == expected[i]);
    }
    SECTION("All duplicate elements") {
        vector<int> nums{1, 1, 1};
        vector<int> expected{1};
        REQUIRE(s.removeDuplicates(nums) == 1);
        REQUIRE(nums[0] == expected[0]);
    }
    SECTION("All identical elements") {
        vector<int> nums{1, 2, 3, 4};
        vector<int> expected{1, 2, 3, 4};
        REQUIRE(s.removeDuplicates(nums) == 4);
        REQUIRE(nums == expected);
    }
    SECTION("Longer case") {
        vector<int> nums{1, 2, 2, 3, 3, 3, 4, 5, 5, 6, 9};
        vector<int> expected{1, 2, 3, 4, 5, 6, 9};
        REQUIRE(s.removeDuplicates(nums) == 7);

        for (int i = 0; i < 7; i++)
            REQUIRE(nums[i] == expected[i]);
    }
}
