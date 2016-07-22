#include "catch.hpp"

#include "CourseScheduleII.hpp"

TEST_CASE("Course Schedule II") {
    CourseScheduleII s;
    SECTION("Sample test") {
        vector<pair<int, int>> pre1{{1, 0}};
        vector<int> expected1{0, 1};
        vector<pair<int, int>> pre2{{1, 0},
                                    {0, 1}};
        vector<int> expected2;
        REQUIRE(s.findOrder(2, pre1) == expected1);
        REQUIRE(s.findOrder(2, pre2) == expected2);
        vector<pair<int, int>> pre3{{1, 0},
                                    {2, 0},
                                    {3, 1},
                                    {3, 2}};
        vector<vector<int>> expected3{{0, 1, 2, 3},
                                      {0, 2, 1, 3}};
        vector<int> result3 = s.findOrder(4, pre3);
        REQUIRE_FALSE(find(expected3.begin(), expected3.end(),
                           result3) == expected3.end());
    }
}
