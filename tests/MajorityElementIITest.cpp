#include "catch.hpp"

#include "MajorityElementII.hpp"

TEST_CASE("Majority Element II") {
    MajorityElementII s;

    SECTION("Sample tests") {
        vector<int> nums1 {1, 2, 3, 4};
        REQUIRE(s.majorityElement(nums1).empty());

        vector<int> nums2 {0, 3, 4, 0};
        vector<int> expected2 {0};
        vector<int> result2 = s.majorityElement(nums2);
        REQUIRE(expected2 == result2);
    }
}
