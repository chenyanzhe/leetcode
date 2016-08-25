#include "IntersectionOfTwoArrays.hpp"

#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> IntersectionOfTwoArrays::intersection(vector<int> &nums1, vector<int> &nums2) {
    return intersection_BinarySearch(nums1, nums2);
}

vector<int> IntersectionOfTwoArrays::intersection_HashMap(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> s1, s2;
    vector<int> ret;

    for (auto d : nums1)
        s1.insert(d);

    for (auto d : nums2)
        if (s1.count(d))
            s2.insert(d);

    for (auto d : s2)
        ret.push_back(d);

    return ret;
}

vector<int> IntersectionOfTwoArrays::intersection_BinarySearch(vector<int> &nums1, vector<int> &nums2) {
    sort(nums2.begin(), nums2.end());

    unordered_set<int> set;
    for (int i = 0; i < nums1.size(); i++) {
        if (binarySearch(nums2, nums1[i]))
            set.insert(nums1[i]);
    }

    vector<int> ret;
    for (auto d : set)
        ret.push_back(d);

    return ret;
}

bool IntersectionOfTwoArrays::binarySearch(vector<int> &nums, int target) {
    if (nums.empty()) return false;

    int l = 0, r = nums.size() - 1;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (nums[m] == target)
            return true;
        if (nums[m] < target)
            l = m;
        else
            r = m;
    }

    return nums[l] == target || nums[r] == target;
}
