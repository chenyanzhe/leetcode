#include "catch.hpp"

#include "NumberOfConnectedComponentsInAnUndirectedGraph.hpp"

TEST_CASE("Number of Connected Components in an Undirected Graph") {
    NumberOfConnectedComponentsInAnUndirectedGraph s;
    SECTION("Sample tests") {
        int n1 = 5;
        vector<pair<int, int>> edges1 {{0, 1}, {1, 2}, {3, 4}};
        REQUIRE(s.countComponents(n1, edges1) == 2);

        int n2 = 5;
        vector<pair<int, int>> edges2 {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
        REQUIRE(s.countComponents(n2, edges2) == 1);
    }
}
