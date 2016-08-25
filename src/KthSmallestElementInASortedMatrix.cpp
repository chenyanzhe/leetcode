#include "KthSmallestElementInASortedMatrix.hpp"

#include <algorithm>

using namespace std;

int KthSmallestElementInASortedMatrix::kthSmallest(vector<vector<int>> &matrix, int k) {
    int n = matrix.size();

    int l = matrix[0][0], r = matrix[n - 1][n - 1];
    while (l < r) {
        int m = l + (r - l) / 2;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            cnt += upper_bound(matrix[i].begin(), matrix[i].end(), m) - matrix[i].begin();
        }

        if (cnt < k) l = m + 1;
        else r = m;
    }

    return l;
}