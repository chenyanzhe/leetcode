#include "catch.hpp"

#include "WildcardMatching.hpp"

TEST_CASE("Wildcard Matching") {
    WildcardMatching s;
    SECTION("Sample tests") {
        REQUIRE(s.isMatch("aa", "a") == false);
        REQUIRE(s.isMatch("aa", "aa") == true);
        REQUIRE(s.isMatch("aaa", "aa") == false);
        REQUIRE(s.isMatch("aa", "*") == true);
        REQUIRE(s.isMatch("aa", "a*") == true);
        REQUIRE(s.isMatch("ab", "?*") == true);
        REQUIRE(s.isMatch("aab", "c*a*b") == false);
    }
    SECTION("Efficiency tests") {
        string str1 = "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba";
        string pat1 = "a*******b";
        REQUIRE(s.isMatch(str1, pat1) == false);
        string str2 = "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba";
        string pat2 = "a??????????????????????????????????????????????????a";
        REQUIRE(s.isMatch(str2, pat2) == true);
        string str3 = "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba";
        string pat3 = "a?????????????????????????????????????????????????a";
        REQUIRE(s.isMatch(str3, pat3) == false);
        string str4 = "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba";
        string pat4 = "a?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*?*a";
        REQUIRE(s.isMatch(str4, pat4) == true);
        string str5 =
                "babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb";
        string pat5 = "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a";
        REQUIRE(s.isMatch(str5, pat5) == false);
    }
}
