#ifndef WORD_BREAK_II_HPP_
#define WORD_BREAK_II_HPP_

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class WordBreakII {
public:
    vector<string> wordBreak(string s, unordered_set<string> &wordDict);

private:
    vector<string> wordBreak_helper(string s, unordered_set<string> &wordDict,
                                    unordered_map<string, vector<string>> &cache);
};

#endif // WORD_BREAK_II_HPP_
