#include "catch.hpp"

#include "FirstBadVersion.hpp"

TEST_CASE("First Bad Version") {
    const int N = 2126753390;
    const int M = 1702766719;
    auto isBad = [](int version) {
        return version >= M;
    };
    FirstBadVersion s(isBad);
    SECTION("Sample test") {
        REQUIRE(s.firstBadVersion(N) == M);
    }
}
