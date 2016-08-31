#ifndef WORD_SEARCH_II_HPP_
#define WORD_SEARCH_II_HPP_

#include "ImplementTrie.hpp"

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class WordSearchII {
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words);

private:
    Trie trie;

    void backtrack(vector<vector<char>> &board, int i, int j, string &cur, vector<vector<bool>> &used,
                   unordered_set <string> &result);
};

#endif // WORD_SEARCH_II_HPP_
