#include "IsomorphicStrings.hpp"

#include <vector>

using namespace std;

bool IsomorphicStrings::isIsomorphic(string s, string t) {
    if (s.size() != t.size()) return false;

    vector<int> sMap(256, 0), tMap(256, 0);

    for (int i = 0; i < s.size(); i++) {
        if (sMap[s[i]] != tMap[t[i]])
            return false;

        sMap[s[i]] = tMap[t[i]] = i + 1;
    }

    return true;
}

