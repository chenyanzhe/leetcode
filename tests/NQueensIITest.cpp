#include "catch.hpp"

#include "NQueensII.hpp"

TEST_CASE("N-Queens II") {
    NQueensII s;
    SECTION("Sample test") {
        REQUIRE(s.totalNQueens(4) == 2);
    }
}
