#include "HIndex.hpp"

#include <algorithm>

using namespace std;

int HIndex::hIndex(vector<int> &citations) {
    return hIndexHashTable(citations);
}

int HIndex::hIndexSort(vector<int> &citations) {
    sort(citations.begin(), citations.end());
    int n = citations.size();
    int i = n - 1;
    while (i >= 0 && citations[i] >= n - i)
        i--;
    return n - i - 1;
}

int HIndex::hIndexHashTable(vector<int> &citations) {
    int n = citations.size();
    vector<int> count(n + 1, 0);

    for (auto cite : citations) {
        if (cite <= n)
            count[cite]++;
        else
            count[n]++;
    }

    int h = n;
    int acc = 0;

    while (acc + count[h] < h) {
        acc += count[h];
        h--;
    }

    return h;
}
