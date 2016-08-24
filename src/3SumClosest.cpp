#include "3SumClosest.hpp"

#include <cstdlib>
#include <algorithm>

using namespace std;

int ThreeSumClosest::threeSumClosest(vector<int> &nums, int target) {
    if (nums.size() < 3)
        return 0;

    sort(nums.begin(), nums.end());
    int result = nums[0] + nums[1] + nums[2];
    int gap = abs(nums[0] + nums[1] + nums[2] - target);

    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int t = target - nums[i];
        int j = i + 1;
        int k = nums.size() - 1;

        while (j < k) {
            if (nums[j] + nums[k] == t)
                return target;
            else if (nums[j] + nums[k] < t) {
                if (gap > t - (nums[j] + nums[k])) {
                    gap = t - (nums[j] + nums[k]);
                    result = nums[i] + nums[j] + nums[k];
                }

                while (j < k && nums[j] == nums[j + 1])
                    j++;

                j++;
            } else {
                if (gap > nums[j] + nums[k] - t) {
                    gap = nums[j] + nums[k] - t;
                    result = nums[i] + nums[j] + nums[k];
                }

                while (j < k && nums[k] == nums[k - 1])
                    k--;

                k--;
            }
        }
    }

    return result;
}
