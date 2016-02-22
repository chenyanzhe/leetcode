#include "ClimbingStairs.hpp"

#include <vector>
using namespace std;

int ClimbingStairs::climbStairs(int n)
{
  if (n == 0 || n == 1 || n == 2) {
    return n;
  }

  int a = 1;
  int b = 2;
  
  for (int i = 2; i < n; i++) {
    int c = a + b;
    a = b;
    b = c;
  }
  
  return b;
}
