#include "catch.hpp"

#include "PalindromePartitioningII.hpp"

TEST_CASE("Palindrome Partitioning II") {
    PalindromePartitioningII s;

    SECTION("Sample test") {
        REQUIRE(s.minCut("aab") == 1);
    }
}
