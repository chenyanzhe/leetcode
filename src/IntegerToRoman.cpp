#include "IntegerToRoman.hpp"

#include <vector>
using namespace std;

string Solution::intToRoman(int num)
{
  string ret;
  int l = 1;
  while (num != 0) {
    ret = digitToRoman(num % 10, l) + ret;
    num /= 10;
    l++;
  }
  return ret;
}

string Solution::digitToRoman(int digit, int level)
{
  vector<string> encode {"", "0", "00", "000", "01", "1", "10", "100", "1000", "02"};
  vector<char> base(3);

  switch(level) {
  case 1:
    base[0] = 'I'; base[1] = 'V'; base[2] = 'X';
    break;
  case 2:
    base[0] = 'X'; base[1] = 'L'; base[2] = 'C';
    break;
  case 3:
    base[0] = 'C'; base[1] = 'D'; base[2] = 'M';
    break;
  case 4:
    base[0] = 'M';
    break;
  }

  string ret;
  for (auto c : encode[digit])
    ret.push_back(base[c - '0']);

  return ret;
}
