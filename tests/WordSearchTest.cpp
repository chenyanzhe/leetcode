#include "catch.hpp"

#include "WordSearch.hpp"

TEST_CASE("Word Search") {
	WordSearch s;

	SECTION("Sample tests") {
		vector<vector<char>> board {
			{'A', 'B', 'C', 'E'},
			{'S', 'F', 'C', 'S'},
			{'A', 'D', 'E', 'E'}
		};
		REQUIRE(s.exist(board, "ABCCED"));
		REQUIRE(s.exist(board, "SEE"));
		REQUIRE_FALSE(s.exist(board, "ABCB"));
	}
}