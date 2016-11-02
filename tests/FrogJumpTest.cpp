#include "catch.hpp"

#include "FrogJump.hpp"

TEST_CASE("Frog Jump") {
    FrogJump s;
    SECTION("Sample tests") {
        vector<int> stones1{0, 1, 3, 5, 6, 8, 12, 17};
        REQUIRE(s.canCross(stones1));

        vector<int> stones2{0, 1, 2, 3, 4, 8, 9, 11};
        REQUIRE_FALSE(s.canCross(stones2));

        vector<int> stones3{0, 2};
        REQUIRE_FALSE(s.canCross(stones3));
    }
}
