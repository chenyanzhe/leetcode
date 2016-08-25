#include "RussianDollEnvelopes.hpp"

#include <algorithm>

using namespace std;

int RussianDollEnvelopes::maxEnvelopes(vector<pair<int, int>> &envelopes) {
    if (envelopes.empty()) return 0;

    auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    };

    sort(envelopes.begin(), envelopes.end(), cmp);

    int n = envelopes.size();
    int end = 0;
    vector<int> tails(n, 0);
    for (int i = 0; i < n; i++) {
        int idx = binarySearch(tails, end, envelopes[i].second);
        tails[idx] = envelopes[i].second;
        if (idx == end) end++;
    }

    return end;
}

int RussianDollEnvelopes::binarySearch(vector<int> &tails, int end, int target) {
    if (end == 0) return end;

    int l = 0, r = end - 1;

    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (tails[m] < target)
            l = m;
        else
            r = m;
    }

    if (tails[l] >= target)
        return l;

    if (tails[r] >= target)
        return r;
    else
        return r + 1;
}