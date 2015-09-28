#include "SpiralMatrixII.hpp"

vector<vector<int>> SpiralMatrixII::generateMatrix(int n) {
	vector<vector<int>> ret(n, vector<int>(n, 0));

	int x = 0;
	int y = 0;
	int c = 1;

	while (n > 0) {
		if (n == 1) {
			ret[x][y] = c;
			break;
		} else {
			for (int i = 0; i < n - 1; i++)
				ret[x][y++] = c++;
			for (int i = 0; i < n - 1; i++)
				ret[x++][y] = c++;
			for (int i = 0; i < n - 1; i++)
				ret[x][y--] = c++;
			for (int i = 0; i < n - 1; i++)
				ret[x--][y] = c++;
		}
		x++;
		y++;
		n -= 2;
	}

	return ret;
}