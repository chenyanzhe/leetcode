#include "catch.hpp"

#include "WiggleSortII.hpp"

#include <algorithm>
#include <iostream>
using namespace std;

TEST_CASE("Wiggle Sort II")
{
  WiggleSortII s;
  SECTION("Sample tests") {
    vector<int> nums1 { 1, 5, 1, 1, 6, 4};
    vector<int> nums1_copy = nums1;
    s.wiggleSort(nums1);

    for (int i = 1; i < nums1.size() - 1; i += 2) {
      REQUIRE(nums1[i - 1] < nums1[i]);
      REQUIRE(nums1[i] > nums1[i + 1]);
    }

    sort(nums1.begin(), nums1.end());
    sort(nums1_copy.begin(), nums1_copy.end());
    REQUIRE(nums1 == nums1_copy);
    vector<int> nums2 { 1, 3, 2, 2, 3, 1};
    vector<int> nums2_copy = nums2;
    s.wiggleSort(nums2);

    for (int i = 1; i < nums2.size() - 1; i += 2) {
      REQUIRE(nums2[i - 1] < nums2[i]);
      REQUIRE(nums2[i] > nums2[i + 1]);
    }

    sort(nums2.begin(), nums2.end());
    sort(nums2_copy.begin(), nums2_copy.end());
    REQUIRE(nums2 == nums2_copy);
    vector<int> nums3 { 1, 1, 2, 1, 2, 2, 1};
    vector<int> nums3_copy = nums3;
    s.wiggleSort(nums3);

    for (int i = 1; i < nums3.size() - 1; i += 2) {
      REQUIRE(nums3[i - 1] < nums3[i]);
      REQUIRE(nums3[i] > nums3[i + 1]);
    }

    sort(nums3.begin(), nums3.end());
    sort(nums3_copy.begin(), nums3_copy.end());
    REQUIRE(nums3 == nums3_copy);
    vector<int> nums4 { 5, 3, 1, 2, 6, 7, 8, 5, 5};
    vector<int> nums4_copy = nums4;
    s.wiggleSort(nums4);

    for (int i = 1; i < nums4.size() - 1; i += 2) {
      REQUIRE(nums4[i - 1] < nums4[i]);
      REQUIRE(nums4[i] > nums4[i + 1]);
    }

    sort(nums4.begin(), nums4.end());
    sort(nums4_copy.begin(), nums4_copy.end());
    REQUIRE(nums4 == nums4_copy);
  }
}
