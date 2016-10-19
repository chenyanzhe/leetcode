#include "catch.hpp"

#include "ZigzagIterator.hpp"

TEST_CASE("Zigzag Iterator") {
    SECTION("Sample test") {
        vector<int> v1{1, 2};
        vector<int> v2{3, 4, 5, 6};
        ZigzagIterator s(v1, v2);
        vector<int> expected{1, 3, 2, 4, 5, 6};
        for (auto e : expected) {
            REQUIRE(s.hasNext());
            REQUIRE(s.next() == e);
        }
        REQUIRE_FALSE(s.hasNext());
    }
}
