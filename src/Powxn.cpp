#include "Powxn.hpp"

double Powxn::myPow(double x, int n)
{
  return helper(x, (long) n);
}

double Powxn::helper(double x, long n)
{
  if (n == 0) {
    return 1.0;
  }

  if (n < 0) {
    return helper(1 / x, -n);
  }

  double half = helper(x, n / 2);

  if (n % 2 == 1) {
    return half * half * x;
  } else {
    return half * half;
  }
}
