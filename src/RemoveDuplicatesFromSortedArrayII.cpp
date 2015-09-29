#include "RemoveDuplicatesFromSortedArrayII.hpp"

int RemoveDuplicatesFromSortedArrayII::removeDuplicates(vector<int>& nums)
{
	int sz = nums.size();

	if (sz <= 2) return sz;

	int counter = 0;
	int prev = nums[0];
	int i, j;
	for (i = 1, j = 1; i < sz; i++) {
		if (nums[i] == prev)
			counter++;
		else
			counter = 0;

		prev = nums[i];

		if (counter <= 1)
			nums[j++] = nums[i];
	}

	return j;
}