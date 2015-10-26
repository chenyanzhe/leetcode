#include "3SumClosest.hpp"

#include <algorithm>
#include <climits>
#include <cstdlib>
using namespace std;

int ThreeSumClosest::threeSumClosest(vector<int>& nums, int target)
{
    int result = 0;
    int min_gap = INT_MAX;

    auto begin = nums.begin();
    auto end = nums.end();

    sort(begin, end);
    
    for (auto i = nums.begin(); i < end - 2; i++) {
        auto j = i + 1;
        auto k = end - 1;

        while (j < k) {
            int sum = *i + *j + *k;
            int gap = abs(sum - target);

            if (gap < min_gap) {
                min_gap = gap;
                result = sum;
            }

            if (sum < target) {
                j++;
                while (*j == *(j - 1) && j < k) j++;
            } else {
                k--;
                while (*k == *(k + 1) && j < k) k--;
            }
        }
    }

    return result;
}
