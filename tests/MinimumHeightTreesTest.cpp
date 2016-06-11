#include "catch.hpp"

#include "MinimumHeightTrees.hpp"

#include <algorithm>
using namespace std;

TEST_CASE("Minimum Height Trees")
{
  MinimumHeightTrees s;
  SECTION("Sample tests") {
    int n1 = 4;
    vector<pair<int, int>> edges1 {{1, 0}, {1, 2}, {1, 3}};
    vector<int> expected1 {1};
    vector<int> result1 = s.findMinHeightTrees(n1, edges1);
    REQUIRE(result1 == expected1);
    int n2 = 6;
    vector<pair<int, int>> edges2 {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
    vector<int> expected2 {3, 4};
    vector<int> result2 = s.findMinHeightTrees(n2, edges2);
    sort(result2.begin(), result2.end());
    REQUIRE(result2 == expected2);
  }
  SECTION("Single point") {
    int n = 1;
    vector<pair<int, int>> edges;
    vector<int> expected {0};
    vector<int> result = s.findMinHeightTrees(n, edges);
    REQUIRE(result == expected);
  }
}

