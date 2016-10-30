#include "MaximalRectangle.hpp"

#include <stack>

using namespace std;

int MaximalRectangle::maximalRectangle(vector<vector<char>> &matrix) {
    size_t m = matrix.size();

    if (m == 0) return 0;

    size_t n = matrix[0].size();

    if (n == 0) return 0;

    int ret = 0;
    vector<int> heights(n, 0);

    for (int i = 0; i < m; i++) {
        // update heights
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '0') heights[j] = 0;
            else heights[j]++;
        }

        ret = max(ret, largestRectangleArea(heights));
    }

    return ret;
}

int MaximalRectangle::largestRectangleArea(vector<int> &heights) {
    stack<int> ops;
    heights.push_back(0);
    int ret = 0;

    for (int i = 0; i < heights.size();) {
        if (ops.empty() || heights[ops.top()] <= heights[i])
            ops.push(i++);
        else {
            int t = ops.top();
            ops.pop();
            ret = max(ret, (ops.empty() ? i : i - ops.top() - 1) * heights[t]);
        }
    }

    return ret;
}
