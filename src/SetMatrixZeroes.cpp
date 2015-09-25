#include "SetMatrixZeroes.hpp"

#include <set>
using namespace std;

void SetMatrixZeroes::setZeroes(vector<vector<int>>& matrix)
{
	set<int> row;
	set<int> col;
	int nrow = matrix.size();
	if (nrow == 0) return;
	int ncol = matrix[0].size();
	if (ncol == 0) return;
	for (int i = 0; i < nrow; i++) {
		for (int j = 0; j < ncol; j++) {
			if (matrix[i][j] == 0) {
				row.insert(i);
				col.insert(j);
			}
		}
	}

	for (auto r : row) {
		for (int j = 0; j < ncol; j++) {
			matrix[r][j] = 0;
		}
	}

	for (auto c : col) {
		for (int i = 0; i < nrow; i++) {
			matrix[i][c] = 0;
		}
	}
}