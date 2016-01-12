#ifndef COMBINATION_SUM_HPP_
#define COMBINATION_SUM_HPP_

#include <vector>
using namespace std;

class CombinationSum
{
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target);
private:
  void helper(vector<int>& candidates, int target, vector<int>& result, int l,
              vector<vector<int>>& global);
};

#endif // COMBINATION_SUM_HPP_
