#include "catch.hpp"

#include "SingleNumberII.hpp"

TEST_CASE("Single Number II") {
    SingleNumberII s;
    SECTION("Sample test") {
        vector<int> nums{-1, 2, 3, 2, -1, 2, -1};
        REQUIRE(s.singleNumber(nums) == 3);
    }
}
