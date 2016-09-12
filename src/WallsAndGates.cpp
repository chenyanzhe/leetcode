#include "WallsAndGates.hpp"

#include <queue>

using namespace std;

void WallsAndGates::wallsAndGates(vector<vector<int>> &rooms) {
    if (rooms.empty()) return;

    int m = rooms.size();
    int n = rooms[0].size();

    if (n == 0) return;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (rooms[i][j] == 0) {
                bfs(rooms, i, j, m, n);
            }
        }
    }
}

void WallsAndGates::bfs(vector<vector<int>> &rooms, int i, int j, int m, int n) {
    typedef pair<int, int> state_t;

    auto valid = [&](const state_t &s) {
        const int x = s.first;
        const int y = s.second;

        if (x < 0 || x >= m || y < 0 || y >= n)
            return false;
        return rooms[x][y] > 0;
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

    queue<state_t> q;
    state_t init{i, j};
    q.push(init);
    int level = 0;

    while (!q.empty()) {
        int nums = q.size();
        for (int c = 0; c < nums; c++) {
            state_t t = q.front();
            q.pop();
            for (auto nb : neighbors(t)) {
                const int x = nb.first;
                const int y = nb.second;
                if (rooms[x][y] == INF || rooms[x][y] > level + 1) {
                    rooms[x][y] = level + 1;
                    q.push(nb);
                }
            }
        }
        level++;
    }
}