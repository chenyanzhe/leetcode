#include "LongestPalindromicSubstring.hpp"

#include <vector>
#include <algorithm>

using namespace std;

string LongestPalindromicSubstring::expandAroundCenter(string s, int c1, int c2) {
    int l = c1;
    int r = c2;
    int n = s.size();

    while (l >= 0 && r <= n - 1 && s[l] == s[r]) {
        l--;
        r++;
    }

    return s.substr(l + 1, r - l - 1);
}

string LongestPalindromicSubstring::longestPalindrome_BruteForce(string s) {
    int n = s.size();

    if (n == 0)
        return "";

    string result = s.substr(0, 1);

    for (int i = 0; i < n - 1; i++) {
        string p1 = expandAroundCenter(s, i, i);

        if (p1.size() > result.size())
            result = p1;

        string p2 = expandAroundCenter(s, i, i + 1);

        if (p2.size() > result.size())
            result = p2;
    }

    return result;
}

string LongestPalindromicSubstring::longestPalindrome_Manacher(string str) {
    if (str.empty()) return str;

    string s = "$";
    for (auto c : str) {
        s.append(1, '#');
        s.append(1, c);
    }
    s.append(1, '#');

    vector<int> p(s.size(), 0);
    int mx = 0, id = 0;

    for (int i = 1; i < s.size(); i++) {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while (s[i + p[i]] == s[i - p[i]]) p[i]++;
        if (i + p[i] > mx) {
            mx = i + p[i];
            id = i;
        }
    }

    int maxp = 0;
    for (int i = 1; i < p.size(); i++) {
        if (p[i] > p[maxp])
            maxp = i;
    }
    int len = p[maxp] - 1;
    int cen = maxp / 2 - 1;
    return str.substr(cen - (len - 1) / 2, len);
}

string LongestPalindromicSubstring::longestPalindrome(string s) {
    return longestPalindrome_Manacher(s);
}