#include "catch.hpp"

#include "PartitionEqualSubsetSum.hpp"

TEST_CASE("Partition Equal Subset Sum") {
    PartitionEqualSubsetSum s;
    SECTION("Sample tests") {
        vector<int> nums1{1, 5, 11, 5};
        REQUIRE(s.canPartition(nums1));

        vector<int> nums2{1, 2, 3, 5};
        REQUIRE_FALSE(s.canPartition(nums2));
    }
    SECTION("Order test") {
        vector<int> nums{1, 2, 5};
        REQUIRE_FALSE(s.canPartition(nums));
    }
}
