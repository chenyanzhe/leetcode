#include "PalindromePairs.hpp"

#include <algorithm>

using namespace std;

vector<vector<int>> PalindromePairs::palindromePairs(vector<string> &words) {
    vector<vector<int>> ret;

    if (words.size() < 2) return ret;

    unordered_map<string, int> lookup;
    for (int i = 0; i < words.size(); i++)
        lookup[words[i]] = i;
    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j <= words[i].size(); j++) {
            string str1 = words[i].substr(0, j);
            string str2 = words[i].substr(j);
            if (isPalindrome(str1)) {
                string str2rvs(str2);
                reverse(str2rvs.begin(), str2rvs.end());
                if (lookup.count(str2rvs) && lookup[str2rvs] != i) {
                    vector<int> ans{lookup[str2rvs], i};
                    ret.push_back(ans);
                }
            }
            if (isPalindrome(str2)) {
                string str1rvs(str1);
                reverse(str1rvs.begin(), str1rvs.end());
                if (lookup.count(str1rvs) && lookup[str1rvs] != i && !str2.empty()) {
                    vector<int> ans{i, lookup[str1rvs]};
                    ret.push_back(ans);
                }
            }
        }
    }

    return ret;
}

bool PalindromePairs::isPalindrome(string str) {
    int left = 0;
    int right = str.size() - 1;
    while (left <= right) {
        if (str[left++] != str[right--])
            return false;
    }
    return true;
}
