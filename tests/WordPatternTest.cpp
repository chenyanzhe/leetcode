#include "catch.hpp"

#include "WordPattern.hpp"

TEST_CASE("Word Pattern")
{
  WordPattern s;
  SECTION("Sample test") {
    REQUIRE(s.wordPattern("abba", "dog cat cat dog"));
    REQUIRE_FALSE(s.wordPattern("abba", "dog cat cat fish"));
    REQUIRE_FALSE(s.wordPattern("aaaa", "dog cat cat dog"));
    REQUIRE_FALSE(s.wordPattern("abba", "dog dog dog dog"));
  }
}
