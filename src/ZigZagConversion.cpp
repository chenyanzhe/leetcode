#include "ZigZagConversion.hpp"

#include <vector>
using namespace std;

string Solution::convert(string s, int numRows)
{
  if (numRows == 1) return s;

  vector<string> lines(numRows, "");

  int dir = 1;
  int l = 0;
  for (auto c : s) {
    lines[l].push_back(c);
    if (l == numRows - 1)
      dir = -1;
    if (l == 0)
      dir = 1;
    l += dir;
  }

  string ret = "";
  for (auto line : lines)
    ret += line;
  return ret;
}
