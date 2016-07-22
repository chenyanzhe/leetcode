#include "catch.hpp"

#include "3Sum.hpp"

using namespace std;

TEST_CASE("3Sum") {
    ThreeSum s;
    SECTION("Sample tests") {
        vector<int> nums1{-1, 0, 1, 2, -1, -4};
        vector<vector<int>> result1 = s.threeSum(nums1);
        vector<vector<int>> expected1 = {
                {-1, 0,  1},
                {-1, -1, 2}
        };
        REQUIRE(result1.size() == 2);

        for (auto triplet : expected1)
            REQUIRE(find(result1.begin(), result1.end(), triplet) != result1.end());

        vector<int> nums2{-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
        vector<vector<int>> result2 = s.threeSum(nums2);
        vector<vector<int>> expected2 = {
                {-4, -2, 6},
                {-4, 0,  4},
                {-4, 1,  3},
                {-4, 2,  2},
                {-2, -2, 4},
                {-2, 0,  2}
        };
        REQUIRE(result2.size() == 6);

        for (auto triplet : expected2)
            REQUIRE(find(result2.begin(), result2.end(), triplet) != result2.end());
    }
    SECTION("All duplicates") {
        vector<int> nums1{0, 0, 0};
        vector<vector<int>> expected1 = {{0, 0, 0}};
        vector<vector<int>> result1 = s.threeSum(nums1);
        REQUIRE(result1.size() == 1);
        REQUIRE(result1[0] == expected1[0]);
    }
}
