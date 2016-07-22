#include "catch.hpp"

#include "KthLargestElementInAnArray.hpp"

TEST_CASE("Kth Largest Element in an Array") {
    KthLargestElementInAnArray s;
    SECTION("Sample test") {
        vector<int> nums{3, 2, 1, 5, 6, 4};
        int k = 2;
        REQUIRE(s.findKthLargest(nums, k) == 5);
    }
}
