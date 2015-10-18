#include "MedianOfTwoSortedArrays.hpp"

#include <algorithm>
using namespace std;

double MedianOfTwoSortedArrays::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int m = nums1.size(), n = nums2.size(), mid = (m + n) / 2;
    bool even = ((m + n) & 1) == 0;

    if (m == 0 && n == 0) return 0;
    if (m == 0)
        return !even ? nums2[mid]: (nums2[mid] + nums2[mid - 1]) / 2.0;
    if (n == 0)
        return !even ? nums1[mid]: (nums1[mid] + nums1[mid - 1]) / 2.0;

    int left = max(0, mid - n), right = min(mid, m - 1);

    while (left <= right) {
        int i = (left + right) / 2, j = mid - 1 - i;
        if (j >= 0 && nums1[i] < nums2[j]) left = i + 1;
        else if (j < n - 1 && nums1[i] > nums2[j+1]) right = i - 1;
        else {
            if (!even) return nums1[i];
            else if (j < 0) return (nums1[i-1] + nums1[i]) / 2.0;
            else if (i <= 0) return (nums2[j] + nums1[i]) / 2.0;
            else return (max(nums2[j], nums1[i-1]) + nums1[i]) / 2.0;
        }
    }

    return findMedianSortedArrays(nums2, nums1);
}