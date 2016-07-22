#include "catch.hpp"

#include "LargestDivisibleSubset.hpp"

#include <iostream>

using namespace std;

TEST_CASE("Largest Divisible Subset") {
    LargestDivisibleSubset s;
    SECTION("Sample tests") {
        vector<int> nums1{1, 2, 3};
        vector<vector<int>> expected1{{1, 2},
                                      {1, 3}};
        vector<int> result1 = s.largestDivisibleSubset(nums1);
        sort(result1.begin(), result1.end());
        REQUIRE_FALSE(find(expected1.begin(), expected1.end(),
                           result1) == expected1.end());
        vector<int> nums2{1, 2, 4, 8};
        vector<vector<int>> expected2{{1, 2, 4, 8}};
        vector<int> result2 = s.largestDivisibleSubset(nums2);
        sort(result2.begin(), result2.end());
        REQUIRE_FALSE(find(expected2.begin(), expected2.end(),
                           result2) == expected2.end());
    }
}
