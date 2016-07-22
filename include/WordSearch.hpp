#ifndef WORD_SEARCH_HPP_
#define WORD_SEARCH_HPP_

#include <vector>
#include <string>

using namespace std;

class WordSearch {
public:
    bool exist(vector<vector<char>> &board, string word);

private:
    bool helper(vector<vector<char>> &board, int row, int col,
                const string &word, int start, int M, int N, int sLen);
};

#endif // WORD_SEARCH_HPP_
