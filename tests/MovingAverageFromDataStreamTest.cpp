#include "catch.hpp"

#include "MovingAverageFromDataStream.hpp"

TEST_CASE("Moving Average from Data Stream") {

    SECTION("Sample test") {
        MovingAverage m(3);
        REQUIRE(m.next(1) == 1.0);
        REQUIRE(m.next(10) == (1 + 10) / 2.0);
        REQUIRE(m.next(3) == (1 + 10 + 3) / 3.0);
        REQUIRE(m.next(5) == (10 + 3 + 5) / 3.0);

    }
}
