#include "catch.hpp"

#include "PalindromePartitioning.hpp"

#include <algorithm>
using namespace std;

TEST_CASE("Palindrome Partitioning")
{
  PalindromePartitioning s;
  SECTION("Sample test") {
    vector<vector<string>> expected {
      {"aa", "b"},
      {"a", "a", "b"}
    };
    vector<vector<string>> result = s.partition("aab");
    REQUIRE(result.size() == expected.size());

    for (auto r : result) {
      REQUIRE_FALSE(find(expected.begin(), expected.end(), r) == expected.end());
    }
  }
}
