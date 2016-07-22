#include "CreateMaximumNumber.hpp"

using namespace std;

vector<int> CreateMaximumNumber::maxNumber(vector<int> &nums1,
                                           vector<int> &nums2, int k) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    int m1 = min(k, n1);
    int m2 = min(k, n2);

    if (n1 + n2 == k)
        return mergeNums(nums1, nums2);

    vector<vector<int>> dp1(m1 + 1);
    vector<vector<int>> dp2(m2 + 1);
    helper(nums1, dp1, n1, m1);
    helper(nums2, dp2, n2, m2);
    vector<int> ret;

    for (int a = k - m2; a <= m1; a++) {
        int b = k - a;
        vector<int> t = mergeNums(dp1[a], dp2[b]);

        if (greaterThan(t, 0, ret, 0))
            ret = t;
    }

    return ret;
}

void CreateMaximumNumber::helper(vector<int> &nums, vector<vector<int>> &dp,
                                 int n, int m) {
    for (int i = 1; i <= n; i++) {
        vector<int> pre = dp[0];

        for (int j = 1; j <= m; j++) {
            vector<int> backup = dp[j];
            pre.push_back(nums[i - 1]);

            if (greaterThan(pre, 0, dp[j], 0))
                dp[j] = pre;

            pre = backup;
        }
    }
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
