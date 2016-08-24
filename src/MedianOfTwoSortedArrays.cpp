#include "MedianOfTwoSortedArrays.hpp"

#include <climits>

using namespace std;

double MedianOfTwoSortedArrays::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.empty() && nums2.empty()) return 0;

    int sum = nums1.size() + nums2.size();
    double ret = 0;

    if (sum & 1)
        ret = findKth(nums1, nums2, 0, 0, sum / 2 + 1);
    else
        ret = (findKth(nums1, nums2, 0, 0, sum / 2) + findKth(nums1, nums2, 0, 0, sum / 2 + 1)) / 2.0;

    return ret;
}

double MedianOfTwoSortedArrays::findKth(vector<int> &nums1, vector<int> &nums2, int st1, int st2, int k) {
    if (st1 >= nums1.size()) return nums2[st2 + k - 1];
    if (st2 >= nums2.size()) return nums1[st1 + k - 1];

    if (k == 1) return min(nums1[st1], nums2[st2]);
    int key1 = st1 + k / 2 - 1 >= nums1.size() ? INT_MAX : nums1[st1 + k / 2 - 1];
    int key2 = st2 + k / 2 - 1 >= nums2.size() ? INT_MAX : nums2[st2 + k / 2 - 1];

    if (key1 < key2)
        return findKth(nums1, nums2, st1 + k / 2, st2, k - k / 2);
    else
        return findKth(nums1, nums2, st1, st2 + k / 2, k - k / 2);
}
