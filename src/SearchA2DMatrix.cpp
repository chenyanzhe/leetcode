#include "SearchA2DMatrix.hpp"

bool SearchA2DMatrix::searchMatrix(vector<vector<int>>& matrix, int target)
{
	int nr = matrix.size();
	if (nr == 0) return false;

	int nc = matrix[0].size();
	if (nc == 0) return false;

	return searchMatrix(matrix, target, 0, nr * nc - 1);
}

bool SearchA2DMatrix::searchMatrix(vector<vector<int>>& matrix, int target, int begin, int end)
{
	if (begin > end) return false;

	int mid = (begin + end) / 2;

	int val = getValue(matrix, mid);

	if (target == val)
		return true;
	else if (target < val)
		return searchMatrix(matrix, target, begin, mid - 1);
	else // target > val
		return searchMatrix(matrix, target, mid + 1, end);
}

int SearchA2DMatrix::getValue(vector<vector<int>>& matrix, int i)
{
	int nc = matrix[0].size();
	int ir = i / nc;
	int ic = (i - ir * nc);

	return matrix[ir][ic];
}
