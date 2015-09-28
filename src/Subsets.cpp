#include "Subsets.hpp"

#include <algorithm>
using namespace std;

vector<vector<int>> Subsets::subsets(vector<int>& nums)
{
	vector<vector<int>> res {{}};
	sort(nums.begin(), nums.end());
	helper(res, nums, 0);
	return res;
}

void Subsets::helper(vector<vector<int>> &res, const vector<int>& nums, int k)
{
	if (k == nums.size()) return;

	vector<vector<int>> addon = res;
	for (auto &sub : addon)
		sub.push_back(nums[k]);
	for (auto &sub : addon)
		res.push_back(sub);

	helper(res, nums, k + 1);
}