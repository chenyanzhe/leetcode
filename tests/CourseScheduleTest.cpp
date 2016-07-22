#include "catch.hpp"

#include "CourseSchedule.hpp"

TEST_CASE("Course Schedule") {
    CourseSchedule s;
    SECTION("Sample tests") {
        vector<pair<int, int>> pre1{{1, 0}};
        vector<pair<int, int>> pre2{{1, 0},
                                    {0, 1}};
        REQUIRE(s.canFinish(2, pre1));
        REQUIRE_FALSE(s.canFinish(2, pre2));
    }
}
