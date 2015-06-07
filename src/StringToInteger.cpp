#include "StringToInteger.hpp"

#include <cctype>
#include <climits>
#include <iostream>
using namespace std;

int StringToInteger::myAtoi(string str)
{
  int i = -1;
  while (i + 1 < str.size() && str[i + 1] == ' ')
    i++;
  if (i + 1 == str.size()) return 0;
  if (i != -1) str = str.substr(i + 1);

  bool negative = false;
  if (str[0] == '+' || str[0] == '-') {
    negative = (str[0] == '-');
    str = str.substr(1);
  }
  
  if (str.size() == 0) return 0;

  int j = -1;
  while (j + 1 < str.size() && isdigit(str[j + 1]))
    j++;
  if (j == -1) return 0;
  str = str.substr(0, j + 1);

  if (str.size() > 10) return negative ? INT_MIN : INT_MAX;

  long long int val = 0;
  for (auto c : str)
    val = val * 10 + (c - '0');
  
  if (negative) {
    return -val < INT_MIN ? INT_MIN : -val;
  } else {
    return val > INT_MAX ? INT_MAX : val;
  }
}
