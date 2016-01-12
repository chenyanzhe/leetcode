#include "catch.hpp"

#include "SearchForARange.hpp"

TEST_CASE("Search for a Range")
{
  SearchForARange s;
  SECTION("Sample tests") {
    vector<int> nums {5, 7, 7, 8, 8, 10};
    vector<int> expected_1 {3, 4};
    REQUIRE(s.searchRange(nums, 8) == expected_1);
    vector<int> expected_2 {1, 2};
    REQUIRE(s.searchRange(nums, 7) == expected_2);
    vector<int> expected_3 {0, 0};
    REQUIRE(s.searchRange(nums, 5) == expected_3);
    vector<int> expected_4 {5, 5};
    REQUIRE(s.searchRange(nums, 10) == expected_4);
    vector<int> expected_5 { -1, -1};
    REQUIRE(s.searchRange(nums, 9) == expected_5);
  }
  SECTION("Empty nums") {
    vector<int> nums;
    vector<int> expected { -1, -1};
    REQUIRE(s.searchRange(nums, 8) == expected);
  }
  SECTION("All identical nums") {
    vector<int> nums {5, 5, 5, 5, 5, 5};
    vector<int> expected_1 {0, 5};
    REQUIRE(s.searchRange(nums, 5) == expected_1);
    vector<int> expected_2 { -1, -1};
    REQUIRE(s.searchRange(nums, 6) == expected_2);
  }
  SECTION("Single element") {
    vector<int> nums {5};
    vector<int> expected_1 {0, 0};
    REQUIRE(s.searchRange(nums, 5) == expected_1);
    vector<int> expected_2 { -1, -1};
    REQUIRE(s.searchRange(nums, 6) == expected_2);
  }
}
