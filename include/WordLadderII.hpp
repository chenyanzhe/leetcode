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
    void bfs(unordered_set<string> &wordList, string beginWord, string endWord, vector<vector<string>> &path);

    void genPath(unordered_map<string, vector<string>> &father, vector<vector<string>> &path,
                 string &beginWord, string &currWord, vector<string> &route);
};

#endif // WORD_LADDER_II_HPP_
