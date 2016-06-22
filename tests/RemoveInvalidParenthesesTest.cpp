#include "catch.hpp"

#include "RemoveInvalidParentheses.hpp"

#include <algorithm>
using namespace std;

TEST_CASE("Remove Invalid Parentheses")
{
  RemoveInvalidParentheses s;
  SECTION("Sample test") {
    vector<string> expected = {"()()()", "(())()"};
    vector<string> result = s.removeInvalidParentheses("()())()");
    REQUIRE(expected.size() == result.size());

    for (auto r : result)
      REQUIRE_FALSE(find(expected.begin(), expected.end(), r) == expected.end());
  }
}
