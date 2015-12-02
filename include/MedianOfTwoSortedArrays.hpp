#ifndef MEDIAN_OF_TWO_SORTED_ARRAYS_HPP_
#define MEDIAN_OF_TWO_SORTED_ARRAYS_HPP_

#include <vector>
using namespace std;

class MedianOfTwoSortedArrays {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
private:
    double findMedianSortedArrays(int nums1[], int sz1, int nums2[], int sz2);
    double findKth(int nums1[], int sz1,  int nums2[], int sz2, int k);
};

#endif // MEDIAN_OF_TWO_SORTED_ARRAYS_HPP_
