#ifndef NUMBER_OF_CONNECTED_COMPONENTS_IN_AN_UNDIRECTED_GRAPH_HPP_
#define NUMBER_OF_CONNECTED_COMPONENTS_IN_AN_UNDIRECTED_GRAPH_HPP_

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

class NumberOfConnectedComponentsInAnUndirectedGraph {
public:
    int countComponents(int n, vector<pair<int, int>> &edges);

private:
    void bfs(unordered_map<int, vector<int>> &graph, int p, unordered_set<int> &visited);

    unordered_map<int, vector<int>> graph;
};

#endif // NUMBER_OF_CONNECTED_COMPONENTS_IN_AN_UNDIRECTED_GRAPH_HPP_