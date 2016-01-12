#include "catch.hpp"

#include "IsomorphicStrings.hpp"

TEST_CASE("Isomorphic Strings")
{
  IsomorphicStrings s;
  SECTION("Sample test") {
    REQUIRE(s.isIsomorphic("egg", "add"));
    REQUIRE_FALSE(s.isIsomorphic("foo", "bar"));
    REQUIRE(s.isIsomorphic("paper", "title"));
  }
}
