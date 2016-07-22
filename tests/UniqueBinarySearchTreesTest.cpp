#include "catch.hpp"

#include "UniqueBinarySearchTrees.hpp"

TEST_CASE("Unique Binary Search Trees") {
    UniqueBinarySearchTrees s;
    SECTION("Sample test") {
        REQUIRE(s.numTrees(3) == 5);
    }
}
