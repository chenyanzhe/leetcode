#include "catch.hpp"

#include "MissingRanges.hpp"

#include <climits>

using namespace std;

TEST_CASE("Missing Ranges") {
    MissingRanges s;
    SECTION("Sample tests") {
        vector<string> expected{"2", "4->49", "51->74", "76->99"};

        vector<int> nums{0, 1, 3, 50, 75};
        int lower = 0;
        int upper = 99;

        REQUIRE(s.findMissingRanges(nums, lower, upper) == expected);
    }
    SECTION("Boundary tests") {
        vector<string> expected{"0->" + to_string(INT_MAX - 1)};

        vector<int> nums{INT_MAX};
        int lower = 0;
        int upper = INT_MAX;

        REQUIRE(s.findMissingRanges(nums, lower, upper) == expected);
    }
}
