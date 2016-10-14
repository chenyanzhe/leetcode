#include "catch.hpp"

#include "DesignPhoneDirectory.hpp"

TEST_CASE("Design Phone Directory") {
    SECTION("Sample test") {
        PhoneDirectory s(3);
        vector<int> used(3, 0);

        int i1 = s.get();
        REQUIRE(0 <= i1);
        REQUIRE(i1 < 3);
        REQUIRE(used[i1] == 0);
        used[i1] = 1;

        for (int i = 0; i < 3; i++) {
            if (i == i1)
                REQUIRE_FALSE(s.check(i));
            else
                REQUIRE(s.check(i));
        }

        int i2 = s.get();
        REQUIRE(0 <= i2);
        REQUIRE(i2 < 3);
        REQUIRE(used[i2] == 0);
        used[i2] = 1;

        for (int i = 0; i < 3; i++) {
            if (i == i1 || i == i2)
                REQUIRE_FALSE(s.check(i));
            else
                REQUIRE(s.check(i));
        }

        s.release(i1);

        for (int i = 0; i < 3; i++) {
            if (i == i2)
                REQUIRE_FALSE(s.check(i));
            else
                REQUIRE(s.check(i));
        }
    }
}
