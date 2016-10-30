#ifndef MAXIMAL_RECTANGLE_HPP_
#define MAXIMAL_RECTANGLE_HPP_

#include <vector>

using namespace std;

class MaximalRectangle {
public:
    int maximalRectangle(vector<vector<char>> &matrix);

private:
    int largestRectangleArea(vector<int> &heights);
};

#endif // MAXIMAL_RECTANGLE_HPP_
