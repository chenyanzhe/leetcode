#include "catch.hpp"

#include "TopKFrequentElements.hpp"

TEST_CASE("Top K Frequent Elements") {
    TopKFrequentElements s;
    SECTION("Sample test") {
        vector<int> nums{1, 1, 1, 2, 2, 3};
        int k = 2;
        vector<int> expected{1, 2};
        REQUIRE(s.topKFrequent(nums, k) == expected);
    }
}