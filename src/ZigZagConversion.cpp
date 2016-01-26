#include "ZigZagConversion.hpp"

#include <vector>
using namespace std;

string ZigZagConversion::convert(string s, int numRows)
{
  if (numRows <= 1) {
    return s;
  }

  vector<string> lines(numRows, "");
  int step = 1;
  int row = 0;

  for (auto c : s) {
    lines[row].push_back(c);

    if (row == numRows - 1) {
      step = -1;
    } else if (row == 0) {
      step = 1;
    }

    row += step;
  }

  s.clear();

  for (auto line : lines) {
    s += line;
  }

  return s;
}
