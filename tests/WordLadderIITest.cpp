#include "catch.hpp"

#include "WordLadderII.hpp"

TEST_CASE("Word Ladder II")
{
  WordLadderII s;
  SECTION("Sample test") {
    string beginWord = "hit";
    string endWord = "cog";
    unordered_set<string> wordList = {"hot", "dot", "dog", "lot", "log"};
    vector<vector<string>> expected {
      {"hit", "hot", "dot", "dog", "cog"},
      {"hit", "hot", "lot", "log", "cog"}
    };
    vector<vector<string>> result = s.findLadders(beginWord, endWord, wordList);
    REQUIRE(result.size() == expected.size());

    for (auto r : result) {
      REQUIRE_FALSE(find(expected.begin(), expected.end(), r) == expected.end());
    }
  }
  SECTION("Duplicates test") {
    string beginWord = "red";
    string endWord = "tax";
    unordered_set<string> wordList = {"ted", "tex", "red", "tax", "tad", "den", "rex", "pee"};
    vector<vector<string>> expected {
      {"red", "ted", "tad", "tax"},
      {"red", "ted", "tex", "tax"},
      {"red", "rex", "tex", "tax"}
    };
    vector<vector<string>> result = s.findLadders(beginWord, endWord, wordList);
    REQUIRE(result.size() == expected.size());

    for (auto r : result) {
      REQUIRE_FALSE(find(expected.begin(), expected.end(), r) == expected.end());
    }
  }
}
