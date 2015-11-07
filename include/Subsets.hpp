#ifndef SUBSETS_HPP_
#define SUBSETS_HPP_

#include <vector>
using namespace std;

class Subsets {
private:
	vector<vector<int>> res;
public:
	vector<vector<int>> subsets(vector<int>& nums);
private:
	void dfs(vector<int>& nums, int i, vector<int>& node);
};

#endif // SUBSETS_HPP_