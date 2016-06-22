#include "PermutationSequence.hpp"

string PermutationSequence::getPermutation(int n, int k)
{
  // prepare initial candidates: 1...n
  string s(n, '0');

  for (int i = 0; i < n; i++)
    s[i] += i + 1;

  // prepare the initial factorial number: (n - 1)!
  int base = 1;

  for (int i = 1; i < n; i++)
    base *= i;

  string result;
  --k;

  for (int i = n - 1; i > 0; k %= base, base /= i, i--) {
    auto p = s.begin() + k / base;
    result.push_back(*p);
    s.erase(p);
  }

  result.push_back(s[0]);
  return result;
}
