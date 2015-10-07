#include "InterleavingString.hpp"

#include <vector>
using namespace std;

bool InterleavingString::isInterleave(string s1, string s2, string s3)
{
	int sz1 = s1.size();
	int sz2 = s2.size();
	int sz3 = s3.size();

	// fast path
	if (sz1 + sz2 != sz3) return false;

	vector<vector<bool>> dp(sz1 + 1, vector<bool>(sz2 + 1, false));

	dp[0][0] = true;

	for (int i = 1; i <= sz1; i++)
		dp[i][0] = (s1[i - 1] == s3[i - 1]) ? dp[i - 1][0] : false;

	for (int j = 1; j <= sz2; j++)
		dp[0][j] = (s2[j - 1] == s3[j - 1]) ? dp[0][j - 1] : false;

	for (int i = 1; i <= sz1; i++) {
		for (int j = 1; j <= sz2; j++) {
			dp[i][j] = ((s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) || (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]));
		}
	}
	return dp[sz1][sz2];
}