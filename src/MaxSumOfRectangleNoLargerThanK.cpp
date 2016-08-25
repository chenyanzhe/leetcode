#include "MaxSumOfRectangleNoLargerThanK.hpp"

#include <set>

using namespace std;

int MaxSumOfRectangleNoLargerThanK::maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
    if (matrix.empty()) return 0;
    if (matrix[0].empty()) return 0;

    int m = matrix.size();
    int n = matrix[0].size();
    int best = 0;

    for (int i = 0; i < n; i++) {
        vector<int> cols(m, 0);
        for (int j = i; j < n; j++) {

            for (int r = 0; r < m; r++)
                cols[r] += matrix[r][j];

            set<int> cumset;
            cumset.insert(0);
            int cum = 0;
            for (int r = 0; r < m; r++) {
                cum += cols[r];
                auto it = cumset.lower_bound(cum - k);
                if (it != cumset.end()) best = max(best, cum - *it);
                cumset.insert(cum);
            }
        }
    }

    return best;
}