#include "SearchA2DMatrix.hpp"

bool SearchA2DMatrix::searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int l = 0, r = m * n - 1;

    while (l != r) {
        int mid = (l + r - 1) >> 1;

        if (matrix[mid / n][mid % n] < target)
            l = mid + 1;
        else
            r = mid;
    }

    return matrix[r / n][r % n] == target;
}
