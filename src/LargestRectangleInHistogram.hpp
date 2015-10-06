#ifndef LARGEST_RECTANGLE_IN_HISTOGRAM_HPP_
#define LARGEST_RECTANGLE_IN_HISTOGRAM_HPP_

#include <vector>
using namespace std;

class LargestRectangleInHistogram {
public:
	int largestRectangleArea(vector<int>& height);
private:
	int largestRectangleArea(vector<int>& height, int l, int r);
};

#endif // LARGEST_RECTANGLE_IN_HISTOGRAM_HPP_