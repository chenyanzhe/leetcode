#include "LongestCommonPrefix.hpp"

string Solution::longestCommonPrefix(vector<string>& strs)
{
  if (strs.empty()) return "";

  string ret = strs[0];

  for (size_t i = 1; i < strs.size(); i++) {
    if (ret.empty()) return "";
    size_t j = 0;
    while (j < ret.size() && j < strs[i].size() && ret[j] == strs[i][j])
      j++;
    ret = ret.substr(0, j);
  }

  return ret;
}
