#ifndef PERMUTATIONS_HPP_
#define PERMUTATIONS_HPP_

#include <vector>
using namespace std;

class Permutations {
public:
  vector<vector<int>> permute(vector<int>& nums);
private:
  void permute(vector<int>& nums, int head, int tail, vector<vector<int>>& ret);
  bool duplicate(vector<int>& nums, int head, int tail);
};

#endif // PERMUTATIONS_HPP_
