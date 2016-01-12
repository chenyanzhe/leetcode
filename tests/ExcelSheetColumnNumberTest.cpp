#include "catch.hpp"

#include "ExcelSheetColumnNumber.hpp"

TEST_CASE("Excel Sheet Column Number")
{
  ExcelSheetColumnNumber s;
  SECTION("Sample tests") {
    REQUIRE(s.titleToNumber("A") == 1);
    REQUIRE(s.titleToNumber("B") == 2);
    REQUIRE(s.titleToNumber("C") == 3);
    REQUIRE(s.titleToNumber("Z") == 26);
    REQUIRE(s.titleToNumber("AA") == 27);
    REQUIRE(s.titleToNumber("AB") == 28);
  }
}
