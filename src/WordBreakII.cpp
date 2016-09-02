#include "WordBreakII.hpp"

vector<string> WordBreakII::wordBreak(string s, unordered_set<string> &wordDict) {
    vector<string> result;
    vector<string> cur;
    vector<bool> canBreak(s.size() + 1, true);

    backtrack(s, wordDict, 0, cur, canBreak, result);

    return result;
}

void WordBreakII::backtrack(string &s, unordered_set<string> &wordDict, int depth, vector<string> &cur,
                            vector<bool> &canBreak, vector<string> &result) {
    if (depth == s.size()) {
        string ans = "";
        for (auto &c : cur)
            ans += c + " ";
        ans = ans.substr(0, ans.size() - 1);
        result.push_back(ans);
        return;
    }

    if (!canBreak[depth])
        return;

    for (int i = depth; i < s.size(); i++) {
        string word = s.substr(depth, i - depth + 1);
        if (wordDict.find(word) == wordDict.end() || !canBreak[i + 1])
            continue;

        cur.push_back(word);

        int before = result.size();
        backtrack(s, wordDict, i + 1, cur, canBreak, result);
        if (result.size() == before)
            canBreak[i + 1] = false;

        cur.pop_back();
    }
}