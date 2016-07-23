#include "GroupAnagrams.hpp"

#include <unordered_map>

using namespace std;

vector<vector<string>> GroupAnagrams::groupAnagrams(vector<string> &strs) {
    vector<vector<string>> ret;
    unordered_map<string, vector<string>> rec;

    for (auto s : strs) {
        string key = strSort(s);
        rec[key].push_back(s);
    }

    for (auto p : rec)
        ret.push_back(p.second);

    return ret;
}

string GroupAnagrams::strSort(string &s) {
    vector<int> count(26, 0);
    size_t n = s.length();
    for (int i = 0; i < n; i++)
        count[s[i] - 'a']++;

    string ret(n, 'a');
    int p = 0;
    for (int j = 0; j < 26; j++)
        for (int i = 0; i < count[j]; i++)
            ret[p++] += j;

    return ret;
}
