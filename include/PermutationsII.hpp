#ifndef PERMUTATIONS_II_HPP_
#define PERMUTATIONS_II_HPP_

#include <vector>
using namespace std;

class PermutationsII
{
public:
  vector<vector<int>> permuteUnique(vector<int>& nums);
private:
  void permute(vector<int>& nums, int head, int tail, vector<vector<int>>& ret);
  bool duplicate(vector<int>& nums, int head, int tail);
};

#endif // PERMUTATIONS_II_HPP_
