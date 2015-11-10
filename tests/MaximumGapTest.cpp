#include "catch.hpp"

#include "MaximumGap.hpp"

TEST_CASE("Maximum Gap") {
    MaximumGap s;

    SECTION("Sample test") {
        vector<int> nums {1, 7, 3, 3};
        REQUIRE(s.maximumGap(nums) == 4);
    }

    SECTION("Normal test") {
        vector<int> nums {1, 10000000};
        REQUIRE(s.maximumGap(nums) == 9999999);
    }
}
