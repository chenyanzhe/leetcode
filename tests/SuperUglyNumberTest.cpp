#include "catch.hpp"

#include "SuperUglyNumber.hpp"

TEST_CASE("Super Ugly Number")
{
  SuperUglyNumber s;
  SECTION("Sample tests") {
    vector<int> primes {2, 7, 13, 19};
    vector<int> expected {0, 1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32};

    for (int i = 1; i <= 12; i++)
      REQUIRE(s.nthSuperUglyNumber(i, primes) == expected[i]);
  }
}
