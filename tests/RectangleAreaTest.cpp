#include "catch.hpp"

#include "RectangleArea.hpp"

TEST_CASE("Rectangle Area")
{
  RectangleArea s;
  SECTION("Sample test") {
    REQUIRE(s.computeArea(-5, -2, 3, 1, -3, -3, 3, 3) == 42);
  }
}
