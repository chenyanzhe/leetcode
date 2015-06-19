#include "CountAndSay.hpp"

string CountAndSay::countAndSay(int n)
{
  string ret = "1";

  while (n > 1) {
    string tmp = "";
    int i = 0;
    int j = 0;
    while (i < ret.size()) {
      while (j + 1 < ret.size() && ret[i] == ret[j + 1])
        j++;
      tmp += (j - i) + 1 + '0';
      tmp += ret[i];
      i = j + 1;
      j = i;
    }
    ret = tmp;
    n--;
  }

  return ret;
}
