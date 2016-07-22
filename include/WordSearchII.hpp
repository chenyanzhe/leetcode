#ifndef WORD_SEARCH_II_HPP_
#define WORD_SEARCH_II_HPP_

#include "ImplementTrie.hpp"

#include <vector>
#include <string>
#include <set>

using namespace std;

class WordSearchII {
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words);

private:
    Trie trie;

    void findWords(const vector<vector<char>> &board,
                   vector<vector<bool>> &visited,
                   int row, int col, string word,
                   set<string> &result);
};

#endif // WORD_SEARCH_II_HPP_
