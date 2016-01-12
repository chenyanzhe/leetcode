#include "catch.hpp"

#include "InterleavingString.hpp"

TEST_CASE("Interleaving String")
{
  InterleavingString s;
  SECTION("Sample tests") {
    REQUIRE(s.isInterleave("aabcc", "dbbca", "aadbbcbcac"));
    REQUIRE_FALSE(s.isInterleave("aabcc", "dbbca", "aadbbbaccc"));
  }
}
