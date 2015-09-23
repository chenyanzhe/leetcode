#include "PlusOne.hpp"

vector<int> PlusOne::plusOne(vector<int>& digits)
{
	int sz = digits.size();

	if (sz == 0) return digits;

	bool carry = true;
	for (int i = sz - 1; i >= 0; i--) {
		if (carry) digits[i]++;
		carry = (digits[i] >= 10);
		if (carry) digits[i] -= 10;
		else break;
	}

	if (!carry) return digits;
	vector<int> ret {1};
	for (int i = 0; i < sz; i++)
		ret.push_back(digits[i]);
	return ret;
}