#include "catch.hpp"

#include "MergeIntervals.hpp"

TEST_CASE("Merge Intervals") {
    MergeIntervals s;
    SECTION("Sample test") {
        Interval a(1, 3);
        Interval b(2, 6);
        Interval c(8, 10);
        Interval d(15, 18);
        Interval x(1, 6);
        Interval y(8, 10);
        Interval z(15, 18);
        vector<Interval> intervals{a, b, c, d};
        vector<Interval> expected{x, y, z};
        REQUIRE(s.merge(intervals) == expected);
    }
}
