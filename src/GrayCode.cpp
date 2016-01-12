#include "GrayCode.hpp"

vector<int> GrayCode::grayCode(int n)
{
  vector<int> ret;

  if (n > 0) {
    helper(n, ret);
  } else {
    ret.push_back(0);
  }

  return ret;
}

void GrayCode::helper(int n, vector<int>& res)
{
  if (n == 1) {
    res.push_back(0);
    res.push_back(1);
  } else {
    helper(n - 1, res);
    int sz = res.size();

    for (int i = sz - 1; i >= 0; i--) {
      int val = res[i] | (1 << (n - 1));
      res.push_back(val);
    }
  }
}
