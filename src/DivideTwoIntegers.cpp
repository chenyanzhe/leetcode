#include "DivideTwoIntegers.hpp"

#include <climits>
#include <cstdint>

int DivideTwoIntegers::divide(int dividend, int divisor)
{
  if (divisor == 0) {
    return INT_MAX;
  }

  if (dividend == 0) {
    return 0;
  }

  if (divisor == 1) {
    return dividend;
  }

  if (divisor == -1) {
    return (dividend == INT_MIN) ? INT_MAX : -dividend;
  }

  bool negative = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
  int64_t dividend_64 = dividend;
  int64_t divisor_64 = divisor;
  dividend_64 = (dividend_64 < 0) ? -dividend_64 : dividend_64;
  divisor_64 = (divisor_64 < 0) ? -divisor_64 : divisor_64;

  if (dividend_64 < divisor_64) {
    return 0;
  }

  int64_t leftover = dividend_64;
  int64_t ret = 0;

  while (leftover >= divisor_64) {
    int64_t count = 1;
    int64_t accum = divisor_64;

    while (leftover > accum + accum) {
      count += count;
      accum += accum;
    }

    ret += count;
    leftover -= accum;
  }

  if (negative) {
    ret = -ret;
  }

  if (negative) {
    return (ret >= INT_MIN) ? ret : INT_MAX;
  } else {
    return (ret <= INT_MAX) ? ret : INT_MAX;
  }
}
