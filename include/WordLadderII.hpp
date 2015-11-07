#ifndef WORD_LADDER_II_HPP_
#define WORD_LADDER_II_HPP_

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class WordLadderII {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList);
private:
    void backtrace(unordered_map<string, vector<string>> &father, vector<string> &path, 
        const string &beginWord, const string &endWord, vector<vector<string>> &result);
};

#endif // WORD_LADDER_II_HPP_