#ifndef WORD_SEARCH_HPP_
#define WORD_SEARCH_HPP_

#include <vector>
#include <string>

using namespace std;

class WordSearch {
public:
    bool exist(vector<vector<char>> &board, string word);

private:
    bool backtrack(vector<vector<char>> &board, string &word, int depth, int i, int j, vector<vector<bool>> &used);
};

#endif // WORD_SEARCH_HPP_
