#include "Subsets.hpp"

#include <algorithm>
using namespace std;

vector<vector<int>> Subsets::subsets(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	vector<int> node;
	dfs(nums, 0, node);
	return res;
}

void Subsets::dfs(vector<int>& nums, int i, vector<int>& node)
{
	if (i == nums.size()) {
		res.push_back(node);
		return;
	}

	// choose nums[i]
	node.push_back(nums[i]);
	dfs(nums, i + 1, node);

	// don't choose nums[i]
	node.pop_back();
	dfs(nums, i + 1, node);
}