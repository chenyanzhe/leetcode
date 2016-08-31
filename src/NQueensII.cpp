#include "NQueensII.hpp"

#include <cstdlib>

using namespace std;

int NQueensII::totalNQueens(int n) {
    int result = 0;
    if (n <= 0) return result;

    vector<bool> used(n, false);
    vector<int> cur(n, 0);

    backtrack(n, 0, used, cur, result);

    return result;
}

void NQueensII::backtrack(int n, int depth, vector<bool> &used, vector<int> &cur, int &result) {
    if (depth == n) {
        result++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (used[i]) continue;

        bool conflict = false;
        for (int j = 0; j < depth; j++) {
            if (depth - j == abs(cur[j] - i)) {
                conflict = true;
                break;
            }
        }
        if (conflict) continue;

        used[i] = true;
        cur[depth] = i;

        backtrack(n, depth + 1, used, cur, result);

        used[i] = false;
        cur[depth] = 0;
    }
}