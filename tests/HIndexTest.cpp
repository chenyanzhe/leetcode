#include "catch.hpp"

#include "HIndex.hpp"

TEST_CASE("H-Index") {
    HIndex s;
    SECTION("Sample test") {
        vector<int> nums{3, 0, 6, 1, 5};
        REQUIRE(s.hIndex(nums) == 3);
    }
}
