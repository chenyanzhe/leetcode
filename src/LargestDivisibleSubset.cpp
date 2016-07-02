#include "LargestDivisibleSubset.hpp"

#include <algorithm>
using namespace std;

vector<int> LargestDivisibleSubset::largestDivisibleSubset(vector<int>& nums)
{
  vector<int> ret;
  sort(nums.begin(), nums.end());
  vector<vector<int>> cache(nums.size());

  for (int i = 0; i < nums.size(); i++) {
    vector<int> tmp = helper(nums, i, cache);

    if (tmp.size() > ret.size())
      ret = tmp;
  }

  return ret;
}

vector<int> LargestDivisibleSubset::helper(vector<int>& nums, int i,
    vector<vector<int>>& cache)
{
  if (!cache[i].empty())
    return cache[i];

  vector<int> ret;

  for (int j = i + 1; j < nums.size(); j++) {
    if (nums[j] % nums[i] == 0) {
      vector<int> tmp = helper(nums, j, cache);

      if (tmp.size() > ret.size())
        ret = tmp;
    }
  }

  ret.push_back(nums[i]);
  cache[i] = ret;
  return ret;
}
