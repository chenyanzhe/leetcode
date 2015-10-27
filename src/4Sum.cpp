#include "4Sum.hpp"

#include <algorithm>
using namespace std;

vector<vector<int>> FourSum::fourSum(vector<int>& nums, int target)
{
    vector<vector<int>> result;

    if (nums.size() < 4)
        return result;

    auto begin = nums.begin();
    auto end = nums.end();

    sort(begin, end);

    for (auto i = begin; i < end - 3; i++) {
        if (i > begin && *i == *(i - 1)) continue;
        for (auto j = i + 1; j < end - 2; j++) {
            if (j > i + 1 && *j == *(j - 1)) continue;
            auto k = j + 1;
            auto m = end - 1;
            while (k < m) {
                int sum = *i + *j + *k + *m;
                if (sum == target) {
                    result.push_back({*i, *j, *k, *m});
                    k++;
                    m--;
                    while (*k == *(k - 1) && *m == *(m + 1) && k < m) k++;
                } else if (sum < target) {
                    k++;
                    while (*k == *(k - 1) && k < m) k++;
                } else {
                    m--;
                    while (*m == *(m + 1) && k < m) m--;
                }
            }
        }
    }

    return result;
}
