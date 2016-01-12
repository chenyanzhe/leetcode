#include "ReverseInteger.hpp"

#include <string>
#include <climits>
using namespace std;

int ReverseInteger::reverse(int x)
{
  if (x == 0) {
    return 0;
  }

  // strip sign
  bool negative = x < 0;
  long lx = x;

  if (negative) {
    lx = -lx;
  }

  // convert to reversed string
  string rsx = "";

  while (lx != 0) {
    rsx.push_back(lx % 10 + '0');
    lx /= 10;
  }

  // strip begining zeros
  int i = -1;

  while (rsx[i + 1] == '0') {
    i++;
  }

  if (i != -1) {
    rsx = rsx.substr(i);
  }

  // convert to reversed long
  long rlx = 0;

  for (auto c : rsx) {
    rlx = rlx * 10 + (c - '0');
  }

  // handle overflow and apply sign
  if (negative) {
    return -rlx < INT_MIN ? 0 : -rlx;
  } else {
    return rlx > INT_MAX ? 0 : rlx;
  }
}
