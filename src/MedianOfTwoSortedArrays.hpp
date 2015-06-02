#include <vector>
using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

private:
  double findMedianSortedArrays(const int* nums1, int sz1, const int* nums2, int sz2);
  double findKth(const int* nums1, int sz1, const int* nums2, int sz2, int k);
};
