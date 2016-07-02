#ifndef LARGEST_DIVISIBLE_SUBSET_HPP_
#define LARGEST_DIVISIBLE_SUBSET_HPP_

#include <vector>
using namespace std;

class LargestDivisibleSubset
{
public:
  vector<int> largestDivisibleSubset(vector<int>& nums);
private:
  vector<int> helper(vector<int>& nums, int i, vector<vector<int>>& cache);
};

#endif // LARGEST_DIVISIBLE_SUBSET_HPP_
