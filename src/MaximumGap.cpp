#include "MaximumGap.hpp"

int MaximumGap::maximumGap(vector<int>& nums)
{
    // perform radix sort
    vector<vector<int>> buckets(10);

    // at most ten iterations since 2^32 has 10 digits
    for (int i = 1; i <= 10; i++) {
        // populate buckets
        for (auto n : nums)
            buckets[getNthDigit(n, i)].push_back(n);
        // merge buckets
        nums.clear();
        for (int j = 0; j < 10; j++) {
            nums.insert(nums.end(), buckets[j].begin(), buckets[j].end());
            buckets[j].clear();
        }
    }

    int result = 0;
    for (int i = 1; i < nums.size(); i++) {
        int diff = nums[i] - nums[i-1];
        result = (result < diff) ? diff : result;
    }
    return result;
}

int MaximumGap::getNthDigit(int num, int n)
{
    int result = 0;
    while (n > 0 && num > 0) {
        result = num % 10;
        num = num / 10;
        n--;
    }
    return n > 0 ? 0 : result;
}