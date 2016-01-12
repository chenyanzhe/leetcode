#include "MinimumSizeSubarraySum.hpp"

#include <climits>
using namespace std;

int MinimumSizeSubarraySum::minSubArrayLen(int s, vector<int>& nums)
{
  int result = INT_MAX;
  int begin = 0;
  int end = 0;
  int local = 0;

  for (; end < nums.size(); end++) {
    local += nums[end];

    while (local >= s) {
      result = min(result, end - begin + 1);
      local -= nums[begin++];
    }
  }

  return result == INT_MAX ? 0 : result;
}
