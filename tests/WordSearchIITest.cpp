#include "catch.hpp"

#include "WordSearchII.hpp"

#include <algorithm>
using namespace std;

TEST_CASE("Word Search II") {
    WordSearchII s;

    SECTION("Sample test") {
        vector<string> words {"oath", "pea", "eat", "rain"};
        vector<vector<char>> board {
            {'o', 'a', 'a', 'n'},
            {'e', 't', 'a', 'e'},
            {'i', 'h', 'k', 'r'},
            {'i', 'f', 'l', 'v'}
        };
        vector<string> expected {"eat", "oath"};
        vector<string> result = s.findWords(board, words);
        REQUIRE(expected.size() == result.size());
        for (int i = 0; i < result.size(); i++)
            REQUIRE_FALSE(find(expected.begin(), expected.end(), result[i]) == expected.end());
    }

    SECTION("Duplicates") {
        vector<string> words {"a"};
        vector<vector<char>> board {
            {'a', 'a'}
        };
        vector<string> expected {"a"};
        vector<string> result = s.findWords(board, words);
        REQUIRE(expected.size() == result.size());
        for (int i = 0; i < result.size(); i++)
            REQUIRE_FALSE(find(expected.begin(), expected.end(), result[i]) == expected.end());
    }
}
