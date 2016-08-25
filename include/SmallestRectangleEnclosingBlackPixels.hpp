#ifndef SMALLEST_RECTANGLE_ENCLOSING_BLACK_PIXELS_HPP_
#define SMALLEST_RECTANGLE_ENCLOSING_BLACK_PIXELS_HPP_

#include <vector>

using namespace std;

class SmallestRectangleEnclosingBlackPixels {
public:
    int minArea(vector<vector<char>> &image, int x, int y);

private:
    int binarySearch(vector<vector<char>> &image, int lo, int hi, int min, int max, bool horizontal, bool slo);
};

#endif // SMALLEST_RECTANGLE_ENCLOSING_BLACK_PIXELS_HPP_