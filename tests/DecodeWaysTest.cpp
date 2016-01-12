#include "catch.hpp"

#include "DecodeWays.hpp"

TEST_CASE("Decode Ways")
{
  DecodeWays s;
  SECTION("Sample test") {
    REQUIRE(s.numDecodings("12") == 2);
  }
  SECTION("Normal tests") {
    REQUIRE(s.numDecodings("01") == 0);
    REQUIRE(s.numDecodings("10") == 1);
    REQUIRE(s.numDecodings("11") == 2);
    REQUIRE(s.numDecodings("26") == 2);
    REQUIRE(s.numDecodings("27") == 1);
  }
}
