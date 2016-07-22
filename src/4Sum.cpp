#include "4Sum.hpp"

using namespace std;

vector<vector<int>> FourSum::fourSum(vector<int> &nums, int target) {
    vector<vector<int>> result;

    if (nums.size() < 4)
        return result;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < nums.size(); j++) {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int gap = target - (nums[i] + nums[j]);
            int k = j + 1;
            int m = nums.size() - 1;

            while (k < m) {
                if (nums[k] + nums[m] == gap) {
                    result.push_back({nums[i], nums[j], nums[k], nums[m]});

                    while (k < m && nums[k] == nums[k + 1])
                        k++;

                    while (k < m && nums[m] == nums[m - 1])
                        m--;

                    k++;
                    m--;
                } else if (nums[k] + nums[m] < gap)
                    k++;
                else
                    m--;
            }
        }
    }

    return result;
}
