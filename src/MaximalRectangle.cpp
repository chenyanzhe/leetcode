#include "MaximalRectangle.hpp"

#include "LargestRectangleInHistogram.hpp"

int MaximalRectangle::maximalRectangle(vector<vector<char>>& matrix)
{
  int height = matrix.size();

  if (height == 0)
    return 0;

  int width = matrix[0].size();

  if (width == 0)
    return 0;

  vector<int> cols(width, 0);
  LargestRectangleInHistogram helper;
  int res = 0;

  for (int i = 0; i < height; i++) {
    // prepare cols
    for (int j = 0; j < width; j++) {
      if (matrix[i][j] == '0')
        cols[j] = 0;
      else
        cols[j]++;
    }

    // calculate maximal rectangle at this level
    int area = helper.largestRectangleArea(cols);

    // update global value
    if (area > res)
      res = area;
  }

  return res;
}
