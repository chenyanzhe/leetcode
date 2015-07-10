#include "RotateImage.hpp"

void RotateImage::rotate(vector<vector<int>>& matrix)
{
  int N = matrix.size();
  vector<vector<int>> shadow(N);
  for (int i = 0; i < N; i++)
    shadow[i].resize(N);

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      shadow[j][N - 1 - i] = matrix[i][j];

  matrix = shadow;
}
