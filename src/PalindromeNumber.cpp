#include "PalindromeNumber.hpp"

bool Solution::isPalindrome(int x)
{
  if (x < 0) return false;

  if (0 <= x && x <= 9) return true;

  int digits = 0;
  int _x = x;
  while (_x > 0) {
    digits++;
    _x /= 10;
  }

  for (int i = 1, j = digits; i < j; i++, j--) {
    if (getDigit(x, i) != getDigit(x, j))
      return false;
  }
  return true;
}

int Solution::getDigit(int x, int i)
{
  if (i > 10) return 0;

  int div = 1;
  for (int j = 0; j < i - 1; j++)
    div *= 10;

  return x / div % 10;
}
