#include "catch.hpp"

#include "NumberOfDigitOne.hpp"

TEST_CASE("Number of Digit One")
{
  NumberOfDigitOne s;
  SECTION("Sample test") {
    REQUIRE(s.countDigitOne(13) == 6);
  }
}
