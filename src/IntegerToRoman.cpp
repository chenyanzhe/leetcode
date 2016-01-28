#include "IntegerToRoman.hpp"

#include <vector>
using namespace std;

string IntegerToRoman::intToRoman(int num)
{
  vector<int> values {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  vector<string> strs {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
  string ret = "";

  for (int i = 0; i < values.size(); i++) {
    while (num >= values[i]) {
      num -= values[i];
      ret.append(strs[i]);
    }
  }

  return ret;
}
