#ifndef INTERSECTION_OF_TWO_ARRAYS_HPP_
#define INTERSECTION_OF_TWO_ARRAYS_HPP_

#include <vector>

using namespace std;

class IntersectionOfTwoArrays {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2);

private:
    vector<int> intersection_HashMap(vector<int> &nums1, vector<int> &nums2);

    vector<int> intersection_BinarySearch(vector<int> &nums1, vector<int> &nums2);

    bool binarySearch(vector<int> &nums, int target);
};

#endif // INTERSECTION_OF_TWO_ARRAYS_HPP_
