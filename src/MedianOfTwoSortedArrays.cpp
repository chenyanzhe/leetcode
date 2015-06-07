#include "MedianOfTwoSortedArrays.hpp"

double MedianOfTwoSortedArrays::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
  if (nums1.empty() && nums2.empty())
    return 0;

  return findMedianSortedArrays(nums1.data(), nums1.size(), nums2.data(), nums2.size());
}

double MedianOfTwoSortedArrays::findMedianSortedArrays(const int* nums1, int sz1, const int* nums2, int sz2)
{
  int sz = sz1 + sz2;
  if (sz % 2 == 1)
    return findKth(nums1, sz1, nums2, sz2, sz / 2 + 1);
  else
    return (findKth(nums1, sz1, nums2, sz2, sz / 2) +
            findKth(nums1, sz1, nums2, sz2, sz / 2 + 1)) / 2;
}

double MedianOfTwoSortedArrays::findKth(const int* nums1, int sz1, const int* nums2, int sz2, int k)
{
  if (sz1 > sz2)
    return findKth(nums2, sz2, nums1, sz1, k);
  if (sz1 == 0)
    return nums2[k-1];
  if (k == 1)
    return nums1[0] < nums2[0] ? nums1[0] : nums2[0];

  int p1 = (k / 2 < sz1 ? k / 2 : sz1);
  int p2 = k - p1;
  if (nums1[p1 - 1] < nums2[p2 - 1])
    return findKth(nums1 + p1, sz1 - p1, nums2, sz2, k - p1);
  if (nums1[p1 - 1] > nums2[p2 - 1])
    return findKth(nums1, sz1, nums2 + p2, sz2 - p2, k - p2);
  else
    return nums1[p1 - 1];
}
