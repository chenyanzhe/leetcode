#ifndef RANGE_SUM_QUERY_2D_IMMUTABLE_HPP_
#define RANGE_SUM_QUERY_2D_IMMUTABLE_HPP_

#include <vector>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix);

    int sumRegion(int row1, int col1, int row2, int col2);

private:
    vector<vector<int>> acc;
    int m;
    int n;
};

#endif // RANGE_SUM_QUERY_2D_IMMUTABLE_HPP_
