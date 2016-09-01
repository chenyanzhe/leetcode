#include "Combinations.hpp"

vector<vector<int>> Combinations::combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> cur;
    backtrack(n, k, 1, cur, result);
    return result;
}

void Combinations::backtrack(int n, int k, int depth, vector<int> &cur, vector<vector<int>> &result) {
    if (k == 0) {
        result.push_back(cur);
        return;
    }

    for (int i = depth; i <= n; i++) {
        cur.push_back(i);

        backtrack(n, k - 1, i + 1, cur, result);

        cur.pop_back();
    }
}