#include "MaximalRectangle.hpp"

#include <iostream>

using namespace std;

int MaximalRectangle::maximalRectangle(vector<vector<char>> &matrix) {
    int m = matrix.size();

    if (m == 0) return 0;

    int n = matrix[0].size();

    if (n == 0) return 0;

    int ret = 0;
    vector<int> height(n, 0);
    vector<int> left(n, 0);
    vector<int> right(n, n);

    for (int i = 0; i < m; i++) {
        // height[j] is the continuous 1's height above matrix[i][j]
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1')
                height[j]++;
            else
                height[j] = 0;
        }

        // left[j] is the leftest position where continuous 1 (with height[j]) begins until matrix[i][j]
        int curLeft = 0;

        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1')
                left[j] = max(curLeft, left[j]);
            else {
                left[j] = 0;
                curLeft = j + 1;
            }
        }

        // right[j] is the rightest position where continuous 1 (with height[j]) ends from matrix[i][j]
        int curRight = n;

        for (int j = n - 1; j >= 0; j--) {
            if (matrix[i][j] == '1')
                right[j] = min(curRight, right[j]);
            else {
                right[j] = n;
                curRight = j;
            }
        }

        // comput area for every matrix[i][j], height is height[j], width is right[j] - left[j]
        for (int j = 0; j < n; j++)
            ret = max(ret, (right[j] - left[j]) * height[j]);
    }

    return ret;
}
