#include "IntegerToEnglishWords.hpp"

string IntegerToEnglishWords::numberToWords(int num)
{
  if (num == 0) {
    return "Zero";
  }

  string ret = "";
  int    ib  = 0;

  while (num != 0) {
    int base = num % 1000;

    if (base > 0) {
      if (ib == 0) {
        ret = parse(base);
      } else {
        ret = parse(base) + " " + dict_b[ib] + " " + ret;
      }
    }

    ib++;
    num /= 1000;
  }

  // strip the trailing space
  if (ret[ret.size() - 1] == ' ') {
    ret = ret.substr(0, ret.size() - 1);
  }

  return ret;
}

string IntegerToEnglishWords::parse(int value)
{
  string ret = "";

  if (value >= 100) {
    ret = dict_a[value / 100] + " Hundred";
  }

  value %= 100;

  if (value == 0) {
    return ret;
  } else if (value <= 20) {
    ret += " " + dict_a[value];
  } else {
    int upper = 29;

    while (value > upper) {
      upper += 10;
    }

    ret += " " + dict_a[upper / 10 * 10];

    if (value - upper / 10 * 10 > 0) {
      ret += " " + dict_a[value - upper / 10 * 10];
    }
  }

  if (ret[0] == ' ') {
    ret = ret.substr(1);
  }

  return ret;
}
