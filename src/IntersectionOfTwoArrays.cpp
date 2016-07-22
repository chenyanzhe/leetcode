#include "IntersectionOfTwoArrays.hpp"

#include <unordered_set>

using namespace std;

vector<int> IntersectionOfTwoArrays::intersection(vector<int> &nums1,
                                                  vector<int> &nums2) {
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
