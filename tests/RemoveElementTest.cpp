#include "catch.hpp"

#include "RemoveElement.hpp"

using namespace std;

TEST_CASE("Remove Element") {
    RemoveElement s;
    SECTION("val is not found in nums") {
        vector<int> nums{1, 2, 3, 4};
        vector<int> expected{1, 2, 3, 4};
        REQUIRE(s.removeElement(nums, 5) == 4);
        sort(nums.begin(), nums.end());
        REQUIRE(nums == expected);
    }
    SECTION("val is found in nums exactly once") {
        vector<int> nums{1, 2, 3, 4};
        vector<int> expected{1, 2, 4};
        REQUIRE(s.removeElement(nums, 3) == 3);
        vector<int> result(nums.begin(), nums.begin() + 3);
        sort(result.begin(), result.end());
        REQUIRE(result == expected);
    }
    SECTION("val is found in nums multiple times") {
        vector<int> nums{3, 1, 3, 2, 3, 4, 3};
        vector<int> expected{1, 2, 4};
        REQUIRE(s.removeElement(nums, 3) == 3);
        vector<int> result(nums.begin(), nums.begin() + 3);
        sort(result.begin(), result.end());
        REQUIRE(result == expected);
    }
}
