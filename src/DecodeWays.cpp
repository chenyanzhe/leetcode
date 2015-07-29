#include "DecodeWays.hpp"

#include <vector>
using namespace std;

int DecodeWays::numDecodings(string s)
{
  int sz = s.size();
  if (sz == 0) return 0;

  vector<int> dp(sz + 1, 0);
  dp[0] = 1;
  dp[1] = valid(s.substr(0, 1)) ? 1 : 0;
  for (int i = 2; i <= sz; i++) {
    if (dp[i - 2] && s[i - 2] != '0' && valid(s.substr(i - 2, 2)))
      dp[i] += dp[i - 2];
    if (dp[i - 1] && valid(s.substr(i - 1, 1)))
      dp[i] += dp[i - 1];
  }

  return dp[sz];
}

bool DecodeWays::valid(string s) {
  int val = stoi(s);
  return 1 <= val && val <= 26;
}
