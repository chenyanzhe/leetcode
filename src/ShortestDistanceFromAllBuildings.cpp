#include "ShortestDistanceFromAllBuildings.hpp"

#include <queue>

using namespace std;

int ShortestDistanceFromAllBuildings::shortestDistance(vector<vector<int>> &grid) {
    if (grid.empty()) return -1;

    int m = grid.size();
    int n = grid[0].size();

    if (n == 0) return -1;

    // accumulate distances from all buildings
    vector<vector<int>> distance(m, vector<int>(n, 0));
    // record how many buildings can be reached
    vector<vector<int>> reach(m, vector<int>(n, 0));

    // count how many buildings
    int buildings = 0;
    int ret = INT_MAX;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                buildings++;
                bfs(grid, i, j, m, n, distance, reach);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0 && reach[i][j] == buildings) {
                ret = min(ret, distance[i][j]);
            }
        }
    }

    return ret == INT_MAX ? -1 : ret;
}

void ShortestDistanceFromAllBuildings::bfs(vector<vector<int>> &grid, int i, int j, int m, int n,
                                           vector<vector<int>> &distance, vector<vector<int>> &reach) {
    typedef pair<int, int> state_t;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    auto valid = [&](const state_t &s) {
        const int x = s.first;
        const int y = s.second;
        if (x < 0 || x >= m || y < 0 || y >= n)
            return false;
        return grid[x][y] == 0 && !visited[x][y];
    };

    auto neighbors = [&](const state_t &s) {
        const int x = s.first;
        const int y = s.second;

        vector<state_t> ret;

        state_t up{x - 1, y};
        if (valid(up)) ret.push_back(up);
        state_t down{x + 1, y};
        if (valid(down)) ret.push_back(down);
        state_t left{x, y - 1};
        if (valid(left)) ret.push_back(left);
        state_t right{x, y + 1};
        if (valid(right)) ret.push_back(right);

        return ret;
    };

    auto mark = [&](const state_t &s) {
        const int x = s.first;
        const int y = s.second;

        visited[x][y] = true;
    };

    auto empty = [&](const state_t &s) {
        const int x = s.first;
        const int y = s.second;

        return grid[x][y] == 0;
    };

    queue<state_t> q;
    state_t init{i, j};
    mark(init);
    q.push(init);

    int dist = 0;
    while (!q.empty()) {
        int nums = q.size();
        for (int c = 0; c < nums; c++) {
            state_t t = q.front();
            q.pop();
            if (empty(t)) {
                const int x = t.first;
                const int y = t.second;
                distance[x][y] += dist;
                reach[x][y]++;
            }
            for (auto nb : neighbors(t)) {
                mark(nb);
                q.push(nb);
            }
        }
        dist++;
    }
}