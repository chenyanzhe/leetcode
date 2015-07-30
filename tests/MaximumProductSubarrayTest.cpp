#include "catch.hpp"

#include "MaximumProductSubarray.hpp"

TEST_CASE("Maximum Product Subarray") {
  MaximumProductSubarray s;

  SECTION("Sample test") {
    vector<int> nums {2, 3, -2, 4};
    REQUIRE(s.maxProduct(nums) == 6);
  }

  SECTION("Single element") {
    vector<int> nums {-4};
    REQUIRE(s.maxProduct(nums) == -4);
  }

  SECTION("All negative numbers") {
    vector<int> nums {-4, -3};
    REQUIRE(s.maxProduct(nums) == 12);
  }

  SECTION("Have zero") {
    vector<int> nums {0, 2};
    REQUIRE(s.maxProduct(nums) == 2);
  }

  SECTION("Some negative numbers") {
    vector<int> nums1 {-2, 3, -4};
    REQUIRE(s.maxProduct(nums1) == 24);
    vector<int> nums2 {2, -5, -2, -4, 3};
    REQUIRE(s.maxProduct(nums2) == 24);
  }
}
