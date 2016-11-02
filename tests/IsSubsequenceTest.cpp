#include "catch.hpp"

#include "IsSubsequence.hpp"

TEST_CASE("Is Subsequence") {
    IsSubsequence s;
    SECTION("Sample tests") {
        REQUIRE(s.isSubsequence("abc", "ahbgdc"));
        REQUIRE_FALSE(s.isSubsequence("axc", "ahbgdc"));
    }
}
