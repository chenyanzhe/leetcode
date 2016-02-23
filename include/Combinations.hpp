#ifndef COMBINATIONS_HPP_
#define COMBINATIONS_HPP_

#include <vector>
using namespace std;

class Combinations
{
public:
  vector<vector<int>> combine(int n, int k);
private:
  void helper(vector<vector<int>>& res, vector<int>& temp, int start,
              int n, int k);
};

#endif // COMBINATIONS_HPP_
