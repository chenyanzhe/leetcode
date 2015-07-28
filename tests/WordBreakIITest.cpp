#include "catch.hpp"

#include "WordBreakII.hpp"

#include <algorithm>
using namespace std;

TEST_CASE("Word Break II") {
  WordBreakII s;

  SECTION("Sample test") {
    unordered_set<string> dict {"cat", "cats", "and", "sand", "dog"};
    vector<string> expected {"cats and dog", "cat sand dog"};
    vector<string> result = s.wordBreak("catsanddog", dict);

    REQUIRE(result.size() == 2);
    for (int i = 0; i < 2; i++)
      REQUIRE_FALSE(find(expected.begin(), expected.end(), result[i]) == expected.end());
  }
}
