#include "MinimumHeightTrees.hpp"

#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> MinimumHeightTrees::findMinHeightTrees(int n,
                                                   vector<pair<int, int>> &edges) {
    // no edges
    if (n == 1) return vector<int> {0};

    unordered_map<int, unordered_set<int>> adj;

    for (auto e : edges) {
        adj[e.first].insert(e.second);
        adj[e.second].insert(e.first);
    }

    vector<int> leaves;

    for (auto e : adj)
        if (e.second.size() == 1)
            leaves.push_back(e.first);

    while (n > 2) {
        n -= leaves.size(); // eat up all the leaves
        vector<int> new_leaves;

        for (auto leaf : leaves) {
            int neighbor = *(adj[leaf].begin());
            // erase leaf node from neighbor
            adj[neighbor].erase(leaf);

            if (adj[neighbor].size() == 1)
                new_leaves.push_back(neighbor);
        }

        leaves = new_leaves;
    }

    return leaves;
}
