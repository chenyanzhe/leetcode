#include "catch.hpp"

#include "InsertDeleteGetRandomDuplicatesAllowed.hpp"

TEST_CASE("Insert Delete GetRandom O(1) - Duplicates allowed") {
    RandomizedCollection collection;
    SECTION("Normal test") {
        REQUIRE(collection.insert(1));
        REQUIRE_FALSE(collection.insert(1));
        REQUIRE(collection.insert(2));
        REQUIRE(collection.remove(1));
        REQUIRE(collection.remove(1));
        REQUIRE(collection.getRandom() == 2);
    }
}
