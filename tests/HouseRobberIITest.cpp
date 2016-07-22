#include "catch.hpp"

#include "HouseRobberII.hpp"

TEST_CASE("House Robber II") {
    HouseRobberII s;
    SECTION("Normal tests") {
        vector<int> nums1{1, 2, 3, 4};
        REQUIRE(s.rob(nums1) == 6);
        vector<int> nums2{9, 1, 9, 9, 1, 9};
        REQUIRE(s.rob(nums2) == 19);
    }
}
