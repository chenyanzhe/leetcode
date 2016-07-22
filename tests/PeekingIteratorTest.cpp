#include "catch.hpp"

#include "PeekingIterator.hpp"

TEST_CASE("Peeking Iterator") {
    SECTION("Sample test") {
        vector<int> nums{1, 2, 3};
        PeekingIterator s(nums);
        REQUIRE(s.next() == 1);
        REQUIRE(s.peek() == 2);
        REQUIRE(s.next() == 2);
        REQUIRE(s.next() == 3);
        REQUIRE_FALSE(s.hasNext());
    }
}
