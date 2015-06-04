#include "catch.hpp"

#include "ContainerWithMostWater.hpp"
#include <numeric>
#include <algorithm>

TEST_CASE("Container With Most Water") {
  Solution s;

  SECTION("Normal tests") {
    vector<int> h1 {3, 7, 1, 6};
    REQUIRE(s.maxArea(h1) == 12);

    vector<int> h2 {3, 2, 2, 10, 1, 9, 4};
    REQUIRE(s.maxArea(h2) == 18);
  }

  SECTION("Heights in increasing and decreasing order") {
    vector<int> h(100);
    iota(h.begin(), h.end(), 1);
    REQUIRE(s.maxArea(h) == 2500);

    reverse(h.begin(), h.end());
    REQUIRE(s.maxArea(h) == 2500);
  }

  SECTION("Same heights") {
    vector<int> h(100, 3);
    REQUIRE(s.maxArea(h) == 3 * 99);
  }
}
