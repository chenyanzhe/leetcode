#include "catch.hpp"

#include "DesignTwitter.hpp"

TEST_CASE("Design Twitter") {
    Twitter s;
    SECTION("Sample test") {
        s.postTweet(1, 5);
        vector<int> expected_1{5};
        REQUIRE(s.getNewsFeed(1) == expected_1);

        s.follow(1, 2);
        s.postTweet(2, 6);
        vector<int> expected_2{6, 5};
        REQUIRE(s.getNewsFeed(1) == expected_2);

        s.unfollow(1, 2);
        vector<int> expected_3{5};
        REQUIRE(s.getNewsFeed(1) == expected_3);
    }
}
