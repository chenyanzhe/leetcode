#include "catch.hpp"

#include "GroupAnagrams.hpp"

#include <algorithm>
using namespace std;

TEST_CASE("Group Anagrams")
{
  GroupAnagrams s;
  SECTION("Normal test") {
    vector<string> nums {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> expected {
      {"ate", "eat", "tea"},
      {"nat", "tan"},
      {"bat"}
    };
    vector<vector<string>> results = s.groupAnagrams(nums);
    REQUIRE(results.size() == expected.size());

    for (auto e : expected)
      REQUIRE_FALSE(find(results.begin(), results.end(), e) == results.end());
  }
}
