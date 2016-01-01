#include "catch.hpp"

#include "ValidAnagram.hpp"

TEST_CASE("Valid Anagram") {
  ValidAnagram s;

  SECTION("Sample test") {
    REQUIRE(s.isAnagram("anagram", "nagaram"));
    REQUIRE_FALSE(s.isAnagram("rat", "car"));
  }
}
