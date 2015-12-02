#include "SpiralMatrix.hpp"

vector<int> SpiralMatrix::spiralOrder(vector<vector<int>>& matrix)
{
	vector<int> ret;

	int m = matrix.size();
	if (m == 0) return ret;
	int n = matrix[0].size();

	int x = 0;
	int y = 0;

	while (m > 0 && n > 0) {
		if (m == 1) {
			for (int i = 0; i < n; i++)
				ret.push_back(matrix[x][y++]);
			break;
		} else if (n == 1) {
			for (int i = 0; i < m; i++)
				ret.push_back(matrix[x++][y]);
			break;
		} else {
			for (int i = 0; i < n-1; i++)
				ret.push_back(matrix[x][y++]);
			for (int i = 0; i < m-1; i++)
				ret.push_back(matrix[x++][y]);
			for (int i = 0; i < n-1; i++)
				ret.push_back(matrix[x][y--]);
			for (int i = 0; i < m-1; i++)
				ret.push_back(matrix[x--][y]);
		}
		x++;
		y++;
		m -= 2;
		n -= 2;
	}

	return ret;
}
