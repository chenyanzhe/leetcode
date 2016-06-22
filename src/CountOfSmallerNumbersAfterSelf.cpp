#include "CountOfSmallerNumbersAfterSelf.hpp"

#include <algorithm>
using namespace std;

vector<int> CountOfSmallerNumbersAfterSelf::countSmaller(vector<int>& nums)
{
  vector<int> ret;

  if (nums.empty())
    return ret;

  int min_val = *min_element(nums.begin(), nums.end());
  int max_val = *max_element(nums.begin(), nums.end());
  // shift nums, making it starting from 1
  vector<long> lnums(nums.size(), 0);

  for (int i = 0; i < nums.size(); i++)
    lnums[i] = nums[i] - min_val + 1;

  bit.resize(max_val - min_val + 2, 0);
  ret.resize(nums.size(), 0);

  for (int i = lnums.size() - 1; i >= 0; i--) {
    ret[i] = query(lnums[i] - 1);
    update(lnums[i], 1);
  }

  return ret;
}

int CountOfSmallerNumbersAfterSelf::query(long index)
{
  int sum = 0;

  while (index > 0) {
    sum += bit[index];
    index -= index & (-index);
  }

  return sum;
}

void CountOfSmallerNumbersAfterSelf::update(long index, int val)
{
  long n = bit.size() - 1;

  while (index <= n) {
    bit[index] += val;
    index += index & (-index);
  }
}
