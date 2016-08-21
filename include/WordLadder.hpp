#ifndef WORD_LADDER_HPP_
#define WORD_LADDER_HPP_

#include <string>
#include <unordered_set>

using namespace std;

class WordLadder {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string> &wordList);

private:
    void bfs(unordered_set<string> &wordList, string beginWord, string endWord, int &dist);
};

#endif // WORD_LADDER_HPP_
