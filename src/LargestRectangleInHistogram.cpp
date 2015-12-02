#include "LargestRectangleInHistogram.hpp"

#include <stack>
#include <algorithm>
using namespace std;

int LargestRectangleInHistogram::largestRectangleArea(vector<int>& height)
{
	stack<int> ops;
	height.push_back(0);
	int ret = 0;

	for (int i = 0; i < height.size();) {
		if (ops.empty() || height[ops.top()] <= height[i])
			ops.push(i++);
		else {
			int t = ops.top();
			ops.pop();
			ret = max(ret, (ops.empty() ? i : i - ops.top() - 1) * height[t]);
		}
	}

	return ret;
}
