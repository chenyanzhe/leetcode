#include "WiggleSortII.hpp"

#include <algorithm>

using namespace std;

int WiggleSortII::m(int idx, int n) {
    return (2 * idx + 1) % (n | 1);
}

void WiggleSortII::wiggleSort(vector<int> &nums) {
    int n = nums.size();
    // find the median
    auto midptr = nums.begin() + n / 2;
    nth_element(nums.begin(), midptr, nums.end());
    int mid = *midptr;
    // 3-way partition in O(n) time and O(1) space
    int i = 0, j = 0, k = n - 1;

    while (j <= k) {
        if (nums[m(j, n)] > mid) {
            swap(nums[m(i, n)], nums[m(j, n)]);
            i++;
            j++;
        } else if (nums[m(j, n)] < mid) {
            swap(nums[m(j, n)], nums[m(k, n)]);
            k--;
        } else
            j++;
    }
}