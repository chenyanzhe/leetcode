#include "UglyNumberII.hpp"

#include <algorithm>
#include <queue>
#include <cstdint>
using namespace std;

int UglyNumberII::nthUglyNumber(int n)
{
  if (n == 1) {
    return 1;
  }

  queue<uint64_t> q2;
  queue<uint64_t> q3;
  queue<uint64_t> q5;
  int count = 1;
  int next;
  q2.push(2);
  q3.push(3);
  q5.push(5);

  while (count < n) {
    next = std::min(q2.front(), min(q3.front(), q5.front()));

    if (next == q2.front()) {
      int val = q2.front();
      q2.push(val * 2);
      q3.push(val * 3);
      q5.push(val * 5);
      q2.pop();
    } else if (next == q3.front()) {
      int val = q3.front();
      q3.push(val * 3);
      q5.push(val * 5);
      q3.pop();
    } else {
      int val = q5.front();
      q5.push(val * 5);
      q5.pop();
    }

    count++;
  }

  return next;
}
