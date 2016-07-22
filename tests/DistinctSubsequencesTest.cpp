#include "catch.hpp"

#include "DistinctSubsequences.hpp"

TEST_CASE("Distinct Subsequences") {
    DistinctSubsequences s;
    SECTION("Sample tests") {
        REQUIRE(s.numDistinct("rabbbit", "rabbit") == 3);
        REQUIRE(s.numDistinct("aabb", "ab") == 4);
    }
}
