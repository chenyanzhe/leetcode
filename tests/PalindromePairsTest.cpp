#include "catch.hpp"

#include "PalindromePairs.hpp"

#include <algorithm>

using namespace std;

TEST_CASE("Palindrome Pairs") {
    PalindromePairs s;
    SECTION("Sample test") {
        vector<string> words{"bat", "tab", "cat"};
        vector<vector<int>> results = s.palindromePairs(words);
        vector<vector<int>> expected{{0, 1},
                                     {1, 0}};
        REQUIRE(results.size() == expected.size());
        for (int i = 0; i < results.size(); i++)
            REQUIRE_FALSE(find(expected.begin(), expected.end(), results[i]) == expected.end());
    }
}
