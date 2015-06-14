#include "catch.hpp"

#include "NextPermutation.hpp"

TEST_CASE("Next Permutation") {
  NextPermutation s;

  SECTION("Sample tests") {
    vector<int> nums_1 {1, 2, 3};
    vector<int> expected_1 {1, 3, 2};
    s.nextPermutation(nums_1);
    REQUIRE(nums_1 == expected_1);

    vector<int> nums_2 {3, 2, 1};
    vector<int> expected_2 {1, 2, 3};
    s.nextPermutation(nums_2);
    REQUIRE(nums_2 == expected_2);

    vector<int> nums_3 {1, 1, 5};
    vector<int> expected_3 {1, 5, 1};
    s.nextPermutation(nums_3);
    REQUIRE(nums_3 == expected_3);
  }

  SECTION("All identicals but one") {
    vector<int> nums_1 {0, 0, 1};
    vector<int> expected_1 {0, 1, 0};
    s.nextPermutation(nums_1);
    REQUIRE(nums_1 == expected_1);

    vector<int> nums_2 {0, 1, 0};
    vector<int> expected_2 {1, 0, 0};
    s.nextPermutation(nums_2);
    REQUIRE(nums_2 == expected_2);

    vector<int> nums_3 {1, 0, 0};
    vector<int> expected_3 {0, 0, 1};
    s.nextPermutation(nums_3);
    REQUIRE(nums_3 == expected_3);
  }
}
