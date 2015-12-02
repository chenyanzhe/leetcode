#include "WordSearch.hpp"

bool WordSearch::exist(vector<vector<char>>& board, string word)
{
	int nrows = board.size();
	int ncols = board[0].size();
	int wlen = word.size();

	if (nrows == 0 || ncols == 0) return false;
	if (wlen == 0) return true;

	vector<vector<bool>> visited (nrows, vector<bool>(ncols, false));

	for (int i = 0; i < nrows; i++)
		for (int j = 0; j < ncols; j++)
			if (findWord(visited, i, j, 0, board, word)) return true;

	return false;
}

bool WordSearch::findWord(vector<vector<bool>>& visited, int row, int col, int index, const vector<vector<char>>& board, const string& word)
{
	int nrows = board.size();
	int ncols = board[0].size();
	int wlen = word.size();

	if (index >= wlen) return true;

	if (row < 0 || row >= nrows || col < 0 || col >= ncols) return false;

	if (visited[row][col]) return false;

	if (board[row][col] != word[index]) return false;

	visited[row][col] = true;
	if (findWord(visited, row + 1, col, index + 1, board, word)) return true;
	if (findWord(visited, row - 1, col, index + 1, board, word)) return true;
	if (findWord(visited, row, col + 1, index + 1, board, word)) return true;
	if (findWord(visited, row, col - 1, index + 1, board, word)) return true;
	visited[row][col] = false;

	return false;
}
