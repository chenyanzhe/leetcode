#include "SearchA2DMatrixII.hpp"

bool SearchA2DMatrixII::searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();
    if (n == 0) return false;

    int i = 0;
    int j = n - 1;

    // from top right to bottom left
    while (i < m && j >= 0) {
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