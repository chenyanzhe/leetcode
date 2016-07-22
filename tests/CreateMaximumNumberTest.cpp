#include "catch.hpp"

#include "CreateMaximumNumber.hpp"

TEST_CASE("Create Maximum Number") {
    CreateMaximumNumber s;
    SECTION("Sample test") {
        vector<int> nums1{3, 4, 6, 5};
        vector<int> nums2{9, 1, 2, 5, 8, 3};
        int k = 5;
        vector<int> expected{9, 8, 6, 5, 3};
        vector<int> result = s.maxNumber(nums1, nums2, k);
        REQUIRE(result == expected);
    }
    SECTION("Exactly size") {
        vector<int> nums1{6, 7};
        vector<int> nums2{6, 0, 4};
        int k = 5;
        vector<int> expected{6, 7, 6, 0, 4};
        vector<int> result = s.maxNumber(nums1, nums2, k);
        REQUIRE(result == expected);
    }
}
