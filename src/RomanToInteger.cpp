#include "RomanToInteger.hpp"

#include <unordered_map>
using namespace std;

int RomanToInteger::romanToInt(string s)
{
  if (s.size() == 0)
    return 0;

  unordered_map<char, int> mapping {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
  };
  int ret = mapping[s[s.size() - 1]];
  int prev = ret;

  for (int i = s.size() - 2; i >= 0; i--) {
    int curr = mapping[s[i]];

    if (curr >= prev)
      ret += curr;
    else
      ret -= curr;

    prev = curr;
  }

  return ret;
}
