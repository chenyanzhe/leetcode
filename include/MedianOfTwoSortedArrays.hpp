#ifndef MEDIAN_OF_TWO_SORTED_ARRAYS_HPP_
#define MEDIAN_OF_TWO_SORTED_ARRAYS_HPP_

#include <vector>

using namespace std;

class MedianOfTwoSortedArrays {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2);

private:
    double findKth(vector<int> &nums1, vector<int> &nums2, int st1, int st2, int k);
};

#endif // MEDIAN_OF_TWO_SORTED_ARRAYS_HPP_
