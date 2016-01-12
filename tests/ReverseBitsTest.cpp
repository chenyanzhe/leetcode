#include "catch.hpp"

#include "ReverseBits.hpp"

TEST_CASE("Reverse Bits")
{
  ReverseBits s;
  SECTION("Sample test") {
    uint32_t input = 43261596;
    uint32_t expected = 964176192;
    REQUIRE(s.reverseBits(input) == expected);
  }
}
