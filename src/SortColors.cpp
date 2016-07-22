#include "SortColors.hpp"

void SortColors::sortColors(vector<int> &nums) {
    int i = 0, j = 0, k = nums.size() - 1;

    while (j <= k) {
        if (nums[j] < 1)
            swap(nums[i++], nums[j++]);
        else if (nums[j] > 1)
            swap(nums[j], nums[k--]);
        else
            j++;
    }
}
