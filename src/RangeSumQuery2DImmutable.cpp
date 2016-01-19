#include "RangeSumQuery2DImmutable.hpp"

NumMatrix::NumMatrix(vector<vector<int>>& matrix)
{
  int nrows = matrix.size();

  if (nrows == 0) {
    return;
  }

  int ncols = matrix[0].size();
  sum.resize(nrows);

  for (int i = 0; i < nrows; i++) {
    sum[i].resize(ncols);
    int acc = 0;

    for (int j = 0; j < ncols; j++) {
      acc += matrix[i][j];
      sum[i][j] = acc;
    }
  }
}

int NumMatrix::sumRegion(int row1, int col1, int row2, int col2)
{
  int acc = 0;

  for (int i = row1; i <= row2; i++) {
    if (col1 == 0) {
      acc += sum[i][col2];
    } else {
      acc += (sum[i][col2] - sum[i][col1 - 1]);
    }
  }

  return acc;
}