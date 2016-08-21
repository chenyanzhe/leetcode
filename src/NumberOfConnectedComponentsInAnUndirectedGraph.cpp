#include "NumberOfConnectedComponentsInAnUndirectedGraph.hpp"

#include <queue>

using namespace std;

int NumberOfConnectedComponentsInAnUndirectedGraph::countComponents(int n, vector<pair<int, int>> &edges) {
    for (auto p : edges) {
        graph[p.first].push_back(p.second);
    }

    int ret = 0;
    unordered_set<int> visited;

    for (int p = 0; p < n; p++) {
        if (!visited.count(p)) {
            ret++;
            bfs(graph, p, visited);
        }
    }

    return ret;
}

void NumberOfConnectedComponentsInAnUndirectedGraph::bfs(unordered_map<int, vector<int>> &graph, int p,
                                                         unordered_set<int> &visited) {
    queue<int> q;
    q.push(p);
    visited.insert(p);

    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (auto nb : graph[t]) {
            if (!visited.count(nb)) {
                q.push(nb);
                visited.insert(nb);
            }
        }
    }
}