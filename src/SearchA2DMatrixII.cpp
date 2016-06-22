#include "SearchA2DMatrixII.hpp"

bool SearchA2DMatrixII::searchMatrix(vector<vector<int>>& matrix, int target)
{
  int r = matrix.size();
  int c = matrix[0].size();
  int i = 0;
  int j = c - 1;

  while (i < r && j >= 0) {
    int p = matrix[i][j];

    if (p == target)
      return true;
    else if (p < target)
      i++;
    else
      j--;
  }

  return false;
}