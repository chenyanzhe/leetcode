#include "catch.hpp"

#include "DifferentWaysToAddParentheses.hpp"

#include <algorithm>
using namespace std;

TEST_CASE("Different Ways to Add Parentheses")
{
  DifferentWaysToAddParentheses s;
  SECTION("Sample test") {
    string input = "2*3-4*5";
    vector<int> expected { -34, -14, -10, -10, 10};
    vector<int> result = s.diffWaysToCompute(input);
    REQUIRE(result.size() == expected.size());

    for (int i = 0; i < result.size(); i++) {
      REQUIRE_FALSE(find(expected.begin(), expected.end(),
                         result[i]) == expected.end());
    }
  }
}
