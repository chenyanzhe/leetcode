#ifndef COMBINATION_SUM_III_HPP_
#define COMBINATION_SUM_III_HPP_

#include <vector>
using namespace std;

class CombinationSumIII
{
public:
  vector<vector<int>> combinationSum3(int k, int n);
private:
  void bt(int k, int n, int i, vector<int>& now, vector<vector<int>>& result);
};

#endif // COMBINATION_SUM_III_HPP_
