#include "SpiralMatrix.hpp"

vector<int> SpiralMatrix::spiralOrder(vector<vector<int>> &matrix) {
    vector<int> res;

    if (matrix.size() == 0)
        return res;

    int rowBegin = 0;
    int rowEnd = matrix.size() - 1;
    int colBegin = 0;
    int colEnd = matrix[0].size() - 1;

    while (rowBegin <= rowEnd && colBegin <= colEnd) {
        // traverse right
        for (int j = colBegin; j <= colEnd; j++)
            res.push_back(matrix[rowBegin][j]);

        rowBegin++;

        // traverse down
        for (int i = rowBegin; i <= rowEnd; i++)
            res.push_back(matrix[i][colEnd]);

        colEnd--;

        if (rowBegin <= rowEnd) {
            // traverse left
            for (int j = colEnd; j >= colBegin; j--)
                res.push_back(matrix[rowEnd][j]);
        }

        rowEnd--;

        if (colBegin <= colEnd) {
            // traverse up
            for (int i = rowEnd; i >= rowBegin; i--)
                res.push_back(matrix[i][colBegin]);
        }

        colBegin++;
    }

    return res;
}
