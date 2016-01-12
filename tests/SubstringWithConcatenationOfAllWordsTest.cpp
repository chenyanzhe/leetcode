#include "catch.hpp"

#include "SubstringWithConcatenationOfAllWords.hpp"
#include <algorithm>
using namespace std;

TEST_CASE("Substring with Concatenation of All Words")
{
  SubstringWithConcatenationOfAllWords s;
  SECTION("Sample test") {
    string str = "barfoothefoobarman";
    vector<string> words {"foo", "bar"};
    vector<int> expected {0, 9};
    vector<int> result = s.findSubstring(str, words);
    sort(result.begin(), result.end());
    REQUIRE(result == expected);
  }
}
