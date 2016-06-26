#include "PalindromePartitioningII.hpp"

#include <algorithm>
#include <vector>
using namespace std;

int PalindromePartitioningII::minCut(string s)
{
  int n = s.size();
  vector<int> minCuts(n + 1, 0);
  vector<vector<bool>> isPalin(n, vector<bool>(n, false));

  for (int i = 0; i <= n; i++)
    minCuts[i] = i - 1;

  for (int j = 1; j < n; j++) {
    for (int i = j; i >= 0; i--) {
      if (s[i] == s[j] && (i + 1 == j || i == j || isPalin[i + 1][j - 1])) {
        isPalin[i][j] = true;
        minCuts[j + 1] = min(minCuts[j + 1], minCuts[i] + 1);
      }
    }
  }

  return minCuts[n];
}

