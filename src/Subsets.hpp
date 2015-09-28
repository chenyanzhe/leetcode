#ifndef SUBSETS_HPP_
#define SUBSETS_HPP_

#include <vector>
using namespace std;

class Subsets {
public:
	vector<vector<int>> subsets(vector<int>& nums);
private:
	void helper(vector<vector<int>> &res, const vector<int>& nums, int k);
};

#endif // SUBSETS_HPP_