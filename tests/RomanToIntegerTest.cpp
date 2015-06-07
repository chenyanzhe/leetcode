#include "catch.hpp"

#include "RomanToInteger.hpp"

TEST_CASE("Roman To Integer") {
  RomanToInteger s;

  SECTION("Base tests") {
    REQUIRE(s.romanToInt("I") == 1);
    REQUIRE(s.romanToInt("II") == 2);
    REQUIRE(s.romanToInt("III") == 3);
    REQUIRE(s.romanToInt("XL") == 40);
    REQUIRE(s.romanToInt("L") == 50);
    REQUIRE(s.romanToInt("LX") == 60);
    REQUIRE(s.romanToInt("DCC") == 700);
    REQUIRE(s.romanToInt("DCCC") == 800);
    REQUIRE(s.romanToInt("CM") == 900);
    REQUIRE(s.romanToInt("M") == 1000);
    REQUIRE(s.romanToInt("MM") == 2000);
    REQUIRE(s.romanToInt("MMM") == 3000);
  }

  SECTION("Combination tests") {
    REQUIRE(s.romanToInt("LXI") == 61);
    REQUIRE(s.romanToInt("CMLXI") == 961);
    REQUIRE(s.romanToInt("MMCMLXI") == 2961);
  }

  SECTION("Zero tests") {
    REQUIRE(s.romanToInt("CCCXX") == 320);
    REQUIRE(s.romanToInt("DVII") == 507);
    REQUIRE(s.romanToInt("MVI") == 1006);
    REQUIRE(s.romanToInt("MMXXX") == 2030);
    REQUIRE(s.romanToInt("MMXXX") == 2030);
    REQUIRE(s.romanToInt("MMMD") == 3500);
  }
}
