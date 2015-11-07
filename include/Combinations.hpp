#ifndef COMBINATIONS_HPP_
#define COMBINATIONS_HPP_

#include <vector>
using namespace std;

class Combinations {
public:
	vector<vector<int>> combine(int n, int k);
private:
	void dfs(vector<vector<int>> &ret, vector<int> &current, int n, int k, int start);
};

#endif // COMBINATIONS_HPP_