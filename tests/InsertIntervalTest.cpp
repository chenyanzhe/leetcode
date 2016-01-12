#include "catch.hpp"

#include "InsertInterval.hpp"

TEST_CASE("Insert Interval")
{
  InsertInterval s;
  SECTION("Sample test 1") {
    Interval a(1, 3);
    Interval b(6, 9);
    Interval c(2, 5);
    Interval d(1, 5);
    Interval e(6, 9);
    vector<Interval> intervals {a, b};
    vector<Interval> expected {d, e};
    REQUIRE(s.insert(intervals, c) == expected);
  }
  SECTION("Sample test 2") {
    Interval a(1, 2);
    Interval b(3, 5);
    Interval c(6, 7);
    Interval d(8, 10);
    Interval e(12, 16);
    Interval f(4, 9);
    Interval g(1, 2);
    Interval h(3, 10);
    Interval i(12, 16);
    vector<Interval> intervals {a, b, c, d, e};
    vector<Interval> expected {g, h, i};
    REQUIRE(s.insert(intervals, f) == expected);
  }
}
