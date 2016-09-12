#ifndef WALLS_AND_GATES_HPP_
#define WALLS_AND_GATES_HPP_

#include <vector>

using namespace std;

class WallsAndGates {
public:
    void wallsAndGates(vector<vector<int>> &rooms);

private:
    void bfs(vector<vector<int>> &rooms, int i, int j, int m, int n);

    const int INF = 2147483647;
};

#endif // WALLS_AND_GATES_HPP_