#include "PalindromePartitioningII.hpp"

#include <vector>

using namespace std;

int PalindromePartitioningII::minCut(string s) {
    if (s.empty()) return 0;

    int n = s.size();
    vector<int> minCuts(n + 1, 0);
    vector<vector<bool>> dict(n, vector<bool>(n, false));

    for (int l = 1; l <= n; l++) {
        for (int i = 0; i + l <= n; i++) {
            int j = i + l - 1;
            if (s[i] == s[j] && (l <= 3 || dict[i + 1][j - 1]))
                dict[i][j] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        if (dict[0][i]) minCuts[i + 1] = 0;
        else {
            minCuts[i + 1] = i;
            for (int j = 1; j <= i; j++) {
                if (dict[j][i])
                    minCuts[i + 1] = min(minCuts[i + 1], minCuts[j] + 1);
            }
        }
    }

    return minCuts[n];
}

