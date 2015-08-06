#include "catch.hpp"

#include "DistinctSubsequences.hpp"

TEST_CASE("Distinct Subsequences") {
  DistinctSubsequences s;

  SECTION("Sample test") {
    REQUIRE(s.numDistinct("rabbbit", "rabbit") == 3);
  }
}
