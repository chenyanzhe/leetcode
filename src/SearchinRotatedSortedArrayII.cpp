#include "SearchinRotatedSortedArrayII.hpp"

bool SearchinRotatedSortedArrayII::search(vector<int>& nums, int target)
{
	if (nums.empty()) return false;

	return partialSearch(nums, 0, nums.size() - 1, target);
}

bool SearchinRotatedSortedArrayII::partialSearch(vector<int>& nums, int p, int q, int target)
{
	if (p > q) return false;

	
	int m = (p + q) / 2;

	if (nums[m] == target) return true;

	if (nums[p] >= nums[q])
		return partialSearch(nums, p, m - 1, target) || partialSearch(nums, m + 1, q, target);
	else {

		if (target < nums[p] || target > nums[q]) return false;

		if (nums[m] < target) return partialSearch(nums, m + 1, q, target);
		else return partialSearch(nums, p, m - 1, target);
	}
}