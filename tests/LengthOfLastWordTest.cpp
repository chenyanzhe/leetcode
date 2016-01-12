#include "catch.hpp"

#include "LengthOfLastWord.hpp"

TEST_CASE("Length Of Last Word")
{
  LengthOfLastWord s;
  SECTION("Sample test") {
    REQUIRE(s.lengthOfLastWord("Hello World") == 5);
  }
  SECTION("Empty string test") {
    REQUIRE(s.lengthOfLastWord("") == 0);
    REQUIRE(s.lengthOfLastWord("   ") == 0);
  }
  SECTION("Beginning and trailing spaces test") {
    REQUIRE(s.lengthOfLastWord("   sdaf adf   ") == 3);
  }
  SECTION("Single word") {
    REQUIRE(s.lengthOfLastWord("abc") == 3);
  }
}
