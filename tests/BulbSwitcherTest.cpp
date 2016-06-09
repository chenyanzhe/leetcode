#include "catch.hpp"

#include "BulbSwitcher.hpp"

TEST_CASE("Bulb Switcher")
{
  BulbSwitcher s;
  SECTION("Sample test") {
    REQUIRE(s.bulbSwitch(3) == 1);
  }
}