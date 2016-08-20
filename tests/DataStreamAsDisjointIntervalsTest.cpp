#include "catch.hpp"

#include "DataStreamAsDisjointIntervals.hpp"

TEST_CASE("Data Stream as Disjoint Intervals") {
    DataStreamAsDisjointIntervals s;
    SECTION("Sample tests") {
        vector<Interval> step0 = {};
        vector<Interval> step1 = {Interval(1, 1)};
        vector<Interval> step2 = {Interval(1, 1), Interval(3, 3)};
        vector<Interval> step3 = {Interval(1, 1), Interval(3, 3), Interval(7, 7)};
        vector<Interval> step4 = {Interval(1, 3), Interval(7, 7)};
        vector<Interval> step5 = {Interval(1, 3), Interval(6, 7)};

        REQUIRE(s.getIntervals() == step0);
        s.addNum(1);
        REQUIRE(s.getIntervals() == step1);
        s.addNum(3);
        REQUIRE(s.getIntervals() == step2);
        s.addNum(7);
        REQUIRE(s.getIntervals() == step3);
        s.addNum(2);
        REQUIRE(s.getIntervals() == step4);
        s.addNum(6);
        REQUIRE(s.getIntervals() == step5);
    }
}
