#include "SpiralMatrixII.hpp"

vector<vector<int>> SpiralMatrixII::generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n));

    if (n == 0)
        return res;

    int rowBegin = 0;
    int rowEnd = n - 1;
    int colBegin = 0;
    int colEnd = n - 1;
    int num = 1;

    while (rowBegin <= rowEnd && colBegin <= colEnd) {
        // traverse right
        for (int j = colBegin; j <= colEnd; j++)
            res[rowBegin][j] = num++;

        rowBegin++;

        // traverse down
        for (int i = rowBegin; i <= rowEnd; i++)
            res[i][colEnd] = num++;

        colEnd--;

        if (rowBegin <= rowEnd) {
            // traverse left
            for (int j = colEnd; j >= colBegin; j--)
                res[rowEnd][j] = num++;
        }

        rowEnd--;

        if (colBegin <= colEnd) {
            // traverse up
            for (int i = rowEnd; i >= rowBegin; i--)
                res[i][colBegin] = num++;
        }

        colBegin++;
    }

    return res;
}
