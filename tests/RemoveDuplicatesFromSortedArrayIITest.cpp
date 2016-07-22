#include "catch.hpp"

#include "RemoveDuplicatesFromSortedArrayII.hpp"

TEST_CASE("Remove Duplicates from Sorted Array II") {
    RemoveDuplicatesFromSortedArrayII s;
    SECTION("Sample test") {
        vector<int> nums{1, 1, 1, 2, 2, 3};
        vector<int> expected{1, 1, 2, 2, 3};
        int result = s.removeDuplicates(nums);
        REQUIRE(nums.size() >= result);
        REQUIRE(expected.size() == result);

        for (int i = 0; i < result; i++)
            REQUIRE(expected[i] == nums[i]);
    }
}
