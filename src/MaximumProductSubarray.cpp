#include "MaximumProductSubarray.hpp"

#include <algorithm>
using namespace std;

int MaximumProductSubarray::maxProduct(vector<int>& nums)
{
  int n = nums.size();

  if (n == 0)
    return 0;

  vector<int> a(n, 0);
  vector<int> b(n, 0);
  a[0] = b[0] = nums[0];

  for (int i = 1; i < n; i++) {
    int v1 = nums[i];
    int v2 = a[i - 1] * nums[i];
    int v3 = b[i - 1] * nums[i];
    a[i] = max(v1, max(v2, v3));
    b[i] = min(v1, min(v2, v3));
  }

  int ret = a[0];

  for (int i = 1; i < n; i++)
    ret = max(ret, a[i]);

  return ret;
}
