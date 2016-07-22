#include "ValidAnagram.hpp"

#include <vector>

using namespace std;

bool ValidAnagram::isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    vector<int> cnt(26, 0);

    for (int i = 0; i < s.size(); i++) {
        cnt[s[i] - 'a']++;
        cnt[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
        if (cnt[i] != 0) return false;

    return true;
}
