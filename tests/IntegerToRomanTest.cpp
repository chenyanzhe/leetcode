#include "catch.hpp"

#include "IntegerToRoman.hpp"

TEST_CASE("Integer To Roman")
{
  IntegerToRoman s;
  SECTION("Base tests") {
    REQUIRE(s.intToRoman(1) == "I");
    REQUIRE(s.intToRoman(2) == "II");
    REQUIRE(s.intToRoman(3) == "III");
    REQUIRE(s.intToRoman(40) == "XL");
    REQUIRE(s.intToRoman(50) == "L");
    REQUIRE(s.intToRoman(60) == "LX");
    REQUIRE(s.intToRoman(700) == "DCC");
    REQUIRE(s.intToRoman(800) == "DCCC");
    REQUIRE(s.intToRoman(900) == "CM");
    REQUIRE(s.intToRoman(1000) == "M");
    REQUIRE(s.intToRoman(2000) == "MM");
    REQUIRE(s.intToRoman(3000) == "MMM");
  }
  SECTION("Combination tests") {
    REQUIRE(s.intToRoman(61) == "LXI");
    REQUIRE(s.intToRoman(961) == "CMLXI");
    REQUIRE(s.intToRoman(2961) == "MMCMLXI");
  }
  SECTION("Zero tests") {
    REQUIRE(s.intToRoman(320) == "CCCXX");
    REQUIRE(s.intToRoman(507) == "DVII");
    REQUIRE(s.intToRoman(1006) == "MVI");
    REQUIRE(s.intToRoman(2030) == "MMXXX");
    REQUIRE(s.intToRoman(2030) == "MMXXX");
    REQUIRE(s.intToRoman(3500) == "MMMD");
  }
}
