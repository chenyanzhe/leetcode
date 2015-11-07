#ifndef SUBSETS_II_HPP_
#define SUBSETS_II_HPP_

#include <vector>
using namespace std;

class SubsetsII {
private:
	vector<vector<int>> res;
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums);
private:
	void dfs(vector<int>& nums, int i, vector<int>& node);
};

#endif // SUBSETS_II_HPP_