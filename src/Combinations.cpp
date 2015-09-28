#include "Combinations.hpp"

vector<vector<int>> Combinations::combine(int n, int k)
{
	vector<vector<int>> ret;
	vector<int> current;
	dfs(ret, current, n, k, 1);

	return ret;
}

void Combinations::dfs(vector<vector<int>> &ret, vector<int> &current, int n, int k, int start)
{
	if (k == 0) {
		ret.push_back(current);
		return;
	}

	for (int i = start; i <= n - k + 1; i++) {
		current.push_back(i);
		dfs(ret, current, n, k - 1, i + 1);
		current.pop_back();
	}
}