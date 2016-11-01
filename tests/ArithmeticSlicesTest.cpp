#include "catch.hpp"

#include "ArithmeticSlices.hpp"

TEST_CASE("Arithmetic Slices") {
    ArithmeticSlices s;
    SECTION("Sample tests") {
        vector<int> nums0{};
        REQUIRE(s.numberOfArithmeticSlices(nums0) == 0);

        vector<int> nums1{1, 2, 3, 4};
        REQUIRE(s.numberOfArithmeticSlices(nums1) == 3);
    }
}
