#include "catch.hpp"

#include "WiggleSubsequence.hpp"

TEST_CASE("Wiggle Subsequence") {
    WiggleSubsequence s;
    SECTION("Sample tests") {
        vector<int> nums0{};
        REQUIRE(s.wiggleMaxLength(nums0) == 0);

        vector<int> nums1{1, 7, 4, 9, 2, 5};
        REQUIRE(s.wiggleMaxLength(nums1) == 6);

        vector<int> nums2{1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
        REQUIRE(s.wiggleMaxLength(nums2) == 7);

        vector<int> nums3{1, 2, 3, 4, 5, 6, 7, 8, 9};
        REQUIRE(s.wiggleMaxLength(nums3) == 2);
    }
}
