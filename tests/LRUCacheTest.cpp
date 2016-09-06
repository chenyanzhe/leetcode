#include "catch.hpp"

#include "LRUCache.hpp"

TEST_CASE("LRU Cache") {
    LRUCache s(2);
    SECTION("Sample test") {
        REQUIRE(s.get(1) == -1);
        REQUIRE(s.get(2) == -1);

        s.set(1, 10);
        REQUIRE(s.get(1) == 10);
        REQUIRE(s.get(2) == -1);

        s.set(2, 20);
        REQUIRE(s.get(1) == 10);
        REQUIRE(s.get(2) == 20);

        s.set(3, 30);
        REQUIRE(s.get(1) == -1);
        REQUIRE(s.get(2) == 20);
        REQUIRE(s.get(3) == 30);

        s.get(2);
        s.set(4, 40);
        REQUIRE(s.get(1) == -1);
        REQUIRE(s.get(2) == 20);
        REQUIRE(s.get(3) == -1);
        REQUIRE(s.get(4) == 40);
    }
}
