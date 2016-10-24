#include "CreateMaximumNumber.hpp"

#include <algorithm>

using namespace std;

vector<int> CreateMaximumNumber::maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    int m1 = min(k, n1);
    int m2 = min(k, n2);

    if (n1 + n2 == k)
        return mergeNums(nums1, nums2);

    vector<int> ret;

    for (int a = k - m2; a <= m1; a++) {
        int b = k - a;

        vector<int> part1 = findMaxKNumbers(nums1, a);
        vector<int> part2 = findMaxKNumbers(nums2, b);
        vector<int> t = mergeNums(part1, part2);

        if (greaterThan(t, 0, ret, 0))
            ret = t;
    }

    return ret;
}

vector<int> CreateMaximumNumber::mergeNums(vector<int> &a, vector<int> &b) {
    int n1 = a.size();
    int n2 = b.size();
    int n = n1 + n2;
    vector<int> ret(n, 0);

    for (int i = 0, j = 0, r = 0; r < n; r++)
        ret[r] = greaterThan(a, i, b, j) ? a[i++] : b[j++];

    return ret;
}


bool CreateMaximumNumber::greaterThan(vector<int> &nums1, int i,
                                      vector<int> &nums2, int j) {
    while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
        i++;
        j++;
    }

    return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
}

vector<int> CreateMaximumNumber::findMaxKNumbers(vector<int> &nums, int k) {
    vector<int> ret(k, 0);
    if (k == 0) return ret;

    int j = 0; // head of the stack
    int sz = nums.size();
    for (int i = 0; i < sz; i++) {
        while (j > 0 && sz - i + j > k && ret[j - 1] < nums[i])
            j--;
        if (j < k)
            ret[j++] = nums[i];
    }
    return ret;
}
