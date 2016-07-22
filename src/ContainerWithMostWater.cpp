#include "ContainerWithMostWater.hpp"

using namespace std;

int ContainerWithMostWater::maxArea(vector<int> &height) {
    if (height.size() < 2)
        return 0;

    int i = 0;
    int j = height.size() - 1;
    int area = 0;

    while (i < j) {
        area = max(area, min(height[i], height[j]) * (j - i));

        if (height[i] < height[j])
            i++;
        else
            j--;
    }

    return area;
}
