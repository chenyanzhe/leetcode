#include "catch.hpp"

#include "MinStack.hpp"

TEST_CASE("Min Stack") {
    MinStack s;

    SECTION("Sample test") {
        // 2, 4, 1, 7, 3
        s.push(3);
        s.push(7);
        s.push(1);
        s.push(4);
        s.push(2);
        REQUIRE(s.top() == 2);
        REQUIRE(s.getMin() == 1);
        s.pop();
        REQUIRE(s.top() == 4);
        REQUIRE(s.getMin() == 1);
        s.pop();
        REQUIRE(s.top() == 1);
        REQUIRE(s.getMin() == 1);
        s.pop();
        REQUIRE(s.top() == 7);
        REQUIRE(s.getMin() == 3);
    }

    SECTION("Duplicates") {
        // 1, 4, 1, 7, 3
        s.push(3);
        s.push(7);
        s.push(1);
        s.push(4);
        s.push(1);
        REQUIRE(s.top() == 1);
        REQUIRE(s.getMin() == 1);
        s.pop();
        REQUIRE(s.top() == 4);
        REQUIRE(s.getMin() == 1);
        s.pop();
        REQUIRE(s.top() == 1);
        REQUIRE(s.getMin() == 1);
        s.pop();
        REQUIRE(s.top() == 7);
        REQUIRE(s.getMin() == 3);
    }
}
