#include "3Sum.hpp"

#include <algorithm>
using namespace std;

vector<vector<int>> ThreeSum::threeSum(vector<int>& nums)
{
    vector<vector<int>> result;

    int target = 0;

    auto begin = nums.begin();
    auto end = nums.end();

    sort(begin, end);

    for (auto i = begin; i < end - 2; i++) {
        if (i > begin && *i == *(i - 1)) continue;

        auto j = i + 1;
        auto k = end - 1;

        while (j < k) {
            if (*i + *j + *k < target) {
                j++;
                while (*j == *(j - 1) && j < k) j++;
            } else if (*i + *j + *k > target) {
                k--;
                while (*k == *(k + 1) && j < k) k--;
            } else {
                result.push_back({*i, *j, *k});
                j++;
                k--;
                while (*j == *(j - 1) && *k == *(k + 1) && j < k) j++;
            }
        }
    }

    return result;
}
