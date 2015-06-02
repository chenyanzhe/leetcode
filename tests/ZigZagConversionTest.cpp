#include "catch.hpp"

#include "ZigZagConversion.hpp"

TEST_CASE("ZigZag Conversion") {
  Solution s;

  SECTION("Sample test") {
    REQUIRE(s.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
  }

  SECTION("Single row") {
    REQUIRE(s.convert("PAYPALISHIRING", 1) == "PAYPALISHIRING");
  }
}
