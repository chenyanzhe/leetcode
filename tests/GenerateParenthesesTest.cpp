#include "catch.hpp"

#include "GenerateParentheses.hpp"
#include <algorithm>

TEST_CASE("Generate Parentheses") {
  GenerateParentheses s;

  SECTION("Sample test") {
    vector<string> expected = {
      "((()))", "(()())", "(())()", "()(())", "()()()"
    };

    vector<string> results = s.generateParenthesis(3);

    REQUIRE(results.size() == 5);
    for (auto p : expected)
      REQUIRE_FALSE(find(results.begin(), results.end(), p) == results.end());
  }
}
