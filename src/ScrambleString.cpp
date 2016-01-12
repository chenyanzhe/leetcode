#include "ScrambleString.hpp"

// #include <vector>
#include <algorithm>
using namespace std;

bool ScrambleString::isScramble(string s1, string s2)
{
  if (s1.size() != s2.size()) {
    return false;
  }

  int sz = s1.size();

  if (sz == 0) {
    return true;
  }

  // vector<vector<vector<bool>>> dp(sz, vector<vector<bool>>(sz, vector<bool>(sz, false)));
  // for speed reason, do not use vectors
  bool dp[sz][sz][sz];
  fill_n(&dp[0][0][0], sz * sz * sz, false);

  for (int i = 0; i < sz; i++)
    for (int j = 0; j < sz; j++) {
      dp[0][i][j] = s1[i] == s2[j];
    }

  for (int k = 1; k < sz; k++) {
    for (int i = 0; i < sz - k; i++) {
      for (int j = 0; j < sz - k; j++) {
        // consider dp[k][i][j] => [i ... i+k] & [j ... j+k]
        // split it to the following two parts:
        // @ PART I @
        // <[i], [j+k]> && <[i+1, i+k], [j, j+k-1]>
        // <[i, i+1], [j+k-1, j+k]> && <[i+2, j+k], [j, j+k-2]>
        // ...
        // <[i, i+k-1], [j+1, j+k]> && <[i+k], [j]>
        // @ PART II @
        // <[i], [j]> && <[i+1, i+k], [j+1, j+k]>
        // <[i, i+1], [j, j+1]> && <[i+2, j+k], [j+2, j+k]>
        // ...
        // <[i, i+k-1], [j, j+k-1]> && <[i+k], [j+k]>
        for (int l = 0; l < k; l++) {
          if ((dp[l][i][j + k - l] && dp[k - l - 1][i + l + 1][j]) ||
              (dp[l][i][j] && dp[k - l - 1][i + l + 1][j + l + 1])) {
            dp[k][i][j] = true;
            break;
          }
        }
      }
    }
  }

  return dp[sz - 1][0][0];
}
