#include "Subsets.hpp"

#include <algorithm>
using namespace std;

vector<vector<int>> Subsets::subsets(vector<int>& nums)
{
  sort(nums.begin(), nums.end());
  int elem_num = nums.size();
  int subset_num = 1 << elem_num;
  vector<vector<int>> res(subset_num, vector<int>());

  for (int i = 0; i < elem_num; i++)
    for (int j = 0; j < subset_num; j++)
      if ((j >> i) & 1) {
        res[j].push_back(nums[i]);
      }

  return res;
}
