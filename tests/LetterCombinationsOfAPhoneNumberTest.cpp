#include "catch.hpp"

#include "LetterCombinationsOfAPhoneNumber.hpp"
#include <algorithm>
using namespace std;

TEST_CASE("Letter Combinations Of A Phone Number") {
  Solution s;

  SECTION("Sample test") {
    string digits = "23";
    vector<string> expected {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    vector<string> result = s.letterCombinations(digits);
    sort(result.begin(), result.end());
    REQUIRE(result == expected);
  }
}
