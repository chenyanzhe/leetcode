#include "catch.hpp"

#include "MaxSumOfRectangleNoLargerThanK.hpp"

TEST_CASE("Max Sum of Rectangle No Larger Than K") {
    MaxSumOfRectangleNoLargerThanK s;
    SECTION("Sample tests") {
        vector<vector<int>> matrix1{{1, 0,  1},
                                    {0, -2, 3}};
        int k1 = 2;
        REQUIRE(s.maxSumSubmatrix(matrix1, k1) == 2);

        vector<vector<int>> matrix2{{2, 2, -1}};
        int k2 = 0;
        REQUIRE(s.maxSumSubmatrix(matrix2, k2) == -1);
    }
}