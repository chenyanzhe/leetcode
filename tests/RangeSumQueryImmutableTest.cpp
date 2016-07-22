#include "catch.hpp"

#include "RangeSumQueryImmutable.hpp"

TEST_CASE("Range Sum Query - Immutable") {
    SECTION("Sample test") {
        vector<int> nums{-2, 0, 3, -5, 2, -1};
        NumArray numArray(nums);
        REQUIRE(numArray.sumRange(0, 2) == 1);
        REQUIRE(numArray.sumRange(2, 5) == -1);
        REQUIRE(numArray.sumRange(0, 5) == -3);
    }
}
