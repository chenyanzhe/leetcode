#ifndef SHORTEST_DISTANCE_FROM_ALL_BUILDINGS_HPP_
#define SHORTEST_DISTANCE_FROM_ALL_BUILDINGS_HPP_

#include <vector>

using namespace std;

class ShortestDistanceFromAllBuildings {
public:
    int shortestDistance(vector<vector<int>> &grid);

private:
    void bfs(vector<vector<int>> &grid, int i, int j, int m, int n, vector<vector<int>> &distance,
             vector<vector<int>> &reach);
};

#endif // SHORTEST_DISTANCE_FROM_ALL_BUILDINGS_HPP_