#ifndef PERMUTATIONS_HPP_
#define PERMUTATIONS_HPP_

#include <vector>
using namespace std;

class Permutations
{
public:
  vector<vector<int>> permute(vector<int>& nums);
private:
  void helper(vector<int>& nums, int begin, vector<vector<int>>& result);
};

#endif // PERMUTATIONS_HPP_
