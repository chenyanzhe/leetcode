#include "IntersectionOfTwoArraysII.hpp"

using namespace std;

vector<int> IntersectionOfTwoArraysII::intersection(vector<int> &nums1,
                                                    vector<int> &nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0;
    int j = 0;
    vector<int> ret;

    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] == nums2[j]) {
            ret.push_back(nums1[i]);
            i++;
            j++;
        } else if (nums1[i] < nums2[j])
            i++;
        else
            j++;
    }

    return ret;
}
