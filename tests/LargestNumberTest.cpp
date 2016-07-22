#include "catch.hpp"

#include "LargestNumber.hpp"

TEST_CASE("Largest Number") {
    LargestNumber s;
    SECTION("Sample test") {
        vector<int> nums{3, 30, 34, 5, 9};
        REQUIRE(s.largestNumber(nums) == "9534330");
    }
}
