#include "sortColors.hpp"

void SortColors::sortColors(vector<int>& nums)
{
	int cZeros = 0;
	int cOnes = 0;
	int cTwos = 0;

	for (auto i : nums) {
		if (i == 0) cZeros++;
		if (i == 1) cOnes++;
		if (i == 2) cTwos++;
	}

	int i;
	for (i = 0; i < cZeros; i++)
		nums[i] = 0;
	for (; i < cZeros + cOnes; i++)
		nums[i] = 1;
	for (; i < cZeros + cOnes + cTwos; i++)
		nums[i] = 2;
}
