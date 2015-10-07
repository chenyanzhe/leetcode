#include "catch.hpp"

#include "MaximalRectangle.hpp"

TEST_CASE("Maximal Rectangle") {
	MaximalRectangle s;

	SECTION("Sample test") {
		vector<vector<char>> matrix {
			{'0', '0', '1', '0'},
			{'0', '0', '0', '1'},
			{'0', '1', '1', '1'},
			{'0', '0', '1', '1'}
		};

		REQUIRE(s.maximalRectangle(matrix) == 4);
	}

	SECTION("Corner test") {
		vector<vector<char>> matrix {
			{'0'}
		};

		REQUIRE(s.maximalRectangle(matrix) == 0);
	}
}