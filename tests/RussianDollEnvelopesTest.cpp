#include "catch.hpp"

#include "RussianDollEnvelopes.hpp"

TEST_CASE("Russian Doll Envelopes") {
    RussianDollEnvelopes s;
    SECTION("Sample tests") {
        vector<pair<int, int>> envelopes1{{5, 4},
                                          {6, 4},
                                          {6, 7},
                                          {2, 3}};
        REQUIRE(s.maxEnvelopes(envelopes1) == 3);

        vector<pair<int, int>> envelopes2{{30, 50},
                                          {12, 2},
                                          {3,  4},
                                          {12, 15}};
        REQUIRE(s.maxEnvelopes(envelopes2) == 3);

        vector<pair<int, int>> envelopes3{{4, 5},
                                          {4, 6},
                                          {6, 7},
                                          {2, 3},
                                          {1, 1}};
        REQUIRE(s.maxEnvelopes(envelopes3) == 4);
    }
}