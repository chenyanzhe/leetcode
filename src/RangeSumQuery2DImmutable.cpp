#include "RangeSumQuery2DImmutable.hpp"

NumMatrix::NumMatrix(vector<vector<int>>& matrix)
{
  m = matrix.size();

  if (m == 0) {
    return;
  }

  n = matrix[0].size();

  if (n == 0) {
    return;
  }

  vector<vector<int>> acc(m, vector<int>(n, 0));
  acc[0][0] = matrix[0][0];

  for (int i = 1; i < m; i++) {
    acc[i][0] = acc[i - 1][0] + matrix[i][0];
  }

  for (int j = 1; j < n; j++) {
    acc[0][j] = acc[0][j - 1] + matrix[0][j];
  }

  for (int i = 1; i < m; i++)
    for (int j = 1; j < n; j++) {
      acc[i][j] = acc[i - 1][j] + acc[i][j - 1] - acc[i - 1][j - 1] + matrix[i][j];
    }

  this->acc = acc;
}

int NumMatrix::sumRegion(int row1, int col1, int row2, int col2)
{
  if (m == 0 || n == 0) {
    return 0;
  }

  int a = acc[row2][col2];
  int b = 0;

  if (col1 - 1 >= 0) {
    b = acc[row2][col1 - 1];
  }

  int c = 0;

  if (row1 - 1 >= 0) {
    c = acc[row1 - 1][col2];
  }

  int d = 0;

  if (col1 - 1 >= 0 && row1 - 1 >= 0) {
    d = acc[row1 - 1][col1 - 1];
  }

  return a - b - c + d;
}
