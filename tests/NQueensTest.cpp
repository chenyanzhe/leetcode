#include "catch.hpp"

#include "NQueens.hpp"
#include <algorithm>
using namespace std;

TEST_CASE("N Queens") {
  NQueens s;

  SECTION("Sample test") {
    vector<vector<string>> expected {
      {".Q..",
       "...Q",
       "Q...",
       "..Q."},
      {"..Q.",
       "Q...",
       "...Q",
       ".Q.."}
    };

    vector<vector<string>> result = s.solveNQueens(4);
    REQUIRE(result.size() == 2);
    for (int i = 0; i < 2; i++)
      REQUIRE_FALSE(find(result.begin(), result.end(), expected[i]) == result.end());
  }
}
