#include "TopKFrequentElements.hpp"

#include <unordered_map>

using namespace std;

vector<int> TopKFrequentElements::topKFrequent(vector<int> &nums, int k) {
    int n = nums.size();

    vector<int> ret;
    unordered_map<int, int> freqs;
    vector<vector<int>> buckets(n + 1);
    for (auto d : nums)
        freqs[d]++;

    for (auto p : freqs)
        buckets[p.second].push_back(p.first);

    for (int i = n; ret.size() < k && i >= 0; i--)
        if (!buckets[i].empty())
            ret.insert(ret.end(), buckets[i].begin(), buckets[i].end());

    return ret;
}