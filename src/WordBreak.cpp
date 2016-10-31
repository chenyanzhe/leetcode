#include "WordBreak.hpp"

#include <vector>

using namespace std;

bool WordBreak::wordBreak(string s, unordered_set<string> &wordDict) {
    size_t sz = s.size();
    vector<bool> dp(sz + 1, false);

    for (size_t i = 1; i <= sz; i++) {
        if (wordDict.find(s.substr(0, i)) != wordDict.end()) {
            dp[i] = true;
            continue;
        }

        for (size_t j = i - 1; j > 0; j--) {
            if (dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[sz];
}
