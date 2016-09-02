#ifndef WORD_BREAK_II_HPP_
#define WORD_BREAK_II_HPP_

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class WordBreakII {
public:
    vector<string> wordBreak(string s, unordered_set<string> &wordDict);

private:
    void backtrack(string &s, unordered_set<string> &wordDict, int depth, vector<string> &cur,
                   vector<bool> &canBreak, vector<string> &result);
};

#endif // WORD_BREAK_II_HPP_
