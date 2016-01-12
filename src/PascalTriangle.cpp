#include "PascalTriangle.hpp"

vector<vector<int>> PascalTriangle::generate(int numRows)
{
  vector<vector<int>> result;

  for (int i = 1; i <= numRows; i++) {
    if (i == 1) {
      result.push_back({1});
    } else if (i == 2) {
      result.push_back({1, 1});
    } else {
      vector<int> row {1};
      const vector<int>& prev = result[i - 2];

      for (int j = 0; j < i - 2; j++) {
        row.push_back(prev[j] + prev[j + 1]);
      }

      row.push_back(1);
      result.push_back(row);
    }
  }

  return result;
}
