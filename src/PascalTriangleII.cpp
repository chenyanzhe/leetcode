#include "PascalTriangleII.hpp"

vector<int> PascalTriangleII::getRow(int rowIndex)
{
	vector<int> result(rowIndex + 1, 1);
	
	if (rowIndex <= 1) return result;

	for (int j = 2; j <= rowIndex; j++) {
		int backup = 1;
		for (int i = 1; i < j; i++) {
			int tmp = backup + result[i];
			backup = result[i];
			result[i] = tmp;
		}
	}

	return result;
}