#ifndef WORD_BREAK_HPP_
#define WORD_BREAK_HPP_

#include <string>
#include <unordered_set>

using namespace std;

class WordBreak {
public:
    bool wordBreak(string s, unordered_set<string> &wordDict);
};

#endif // WORD_BREAK_HPP_
