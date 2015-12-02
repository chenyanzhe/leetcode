#ifndef WORD_SEARCH_HPP_
#define WORD_SEARCH_HPP_

#include <vector>
#include <string>
using namespace std;

class WordSearch {
public:
    bool exist(vector<vector<char>>& board, string word);
private:
	bool findWord(vector<vector<bool>>& visited, int row, int col, int index, const vector<vector<char>>& board, const string& word);
};

#endif // WORD_SEARCH_HPP_
