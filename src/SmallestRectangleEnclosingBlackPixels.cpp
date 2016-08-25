#include "SmallestRectangleEnclosingBlackPixels.hpp"

int SmallestRectangleEnclosingBlackPixels::minArea(vector<vector<char>> &image, int x, int y) {
    if (image.empty()) return 0;
    if (image[0].empty()) return 0;

    int m = image.size();
    int n = image[0].size();

    int left = binarySearch(image, 0, y, 0, m, true, true);
    int right = binarySearch(image, y + 1, n, 0, m, true, false);
    int up = binarySearch(image, 0, x, left, right, false, true);
    int down = binarySearch(image, x + 1, m, left, right, false, false);

    return (right - left) * (down - up);
}

int SmallestRectangleEnclosingBlackPixels::binarySearch(vector<vector<char>> &image, int lo, int hi, int min, int max,
                                                        bool horizontal, bool slo) {
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        bool hasBlackPixel = false;
        for (int i = min; i < max; i++) {
            if ((horizontal ? image[i][mid] : image[mid][i]) == '1') {
                hasBlackPixel = true;
                break;
            }
        }
        if (hasBlackPixel == slo) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}
