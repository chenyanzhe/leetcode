#include "SplitArrayWithEqualSum.hpp"

bool SplitArrayWithEqualSum::splitArray(vector<int>& nums) {
    if (nums.size() <= 6)
        return false;
    
    int n = nums.size();
    vector<int> aggregate(n + 1, 0);
    for (int i = 0; i < n; i++) {
        aggregate[i + 1] = aggregate[i] + nums[i];
    }

    for (int j = 3; j + 3 < n; j++) {
        set<int> v1, v2;
        if (splitEqual(aggregate, 0, j - 1, v1) &&
            splitEqual(aggregate, j + 1, n - 1, v2)) {
                for (auto c1 : v1) {
                    if (v2.count(c1))
                        return true;
                }
            }
    }

    return false;
}

bool SplitArrayWithEqualSum::splitEqual(vector<int>& agg, int i, int j, set<int>& v) {
    for (int k = i + 1; k + 1 <= j; k++) {
        if (agg[k] - agg[i] == agg[j + 1] - agg[k + 1]) {
            v.insert(agg[k] - agg[i]);
        }
    }
    return !v.empty();
}