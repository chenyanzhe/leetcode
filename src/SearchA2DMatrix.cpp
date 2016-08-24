#include "SearchA2DMatrix.hpp"

bool SearchA2DMatrix::searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;

    int n = matrix[0].size();
    if (n == 0) return false;

    int l = 0, r = m * n - 1;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        int row = mid / n;
        int col = mid % n;

        if (matrix[row][col] < target)
            l = mid;
        else
            r = mid;
    }

    return matrix[l / n][l % n] == target || matrix[r / n][r % n] == target;
}
