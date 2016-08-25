#include "catch.hpp"

#include "MaxSumOfRectangleNoLargerThanK.hpp"

TEST_CASE("Max Sum of Rectangle No Larger Than K") {
    MaxSumOfRectangleNoLargerThanK s;
    SECTION("Sample tests") {
        vector<vector<int>> matrix{{1, 0,  1},
                                   {0, -2, 3}};
        int k = 2;
        REQUIRE(s.maxSumSubmatrix(matrix, k) == 2);
    }
}