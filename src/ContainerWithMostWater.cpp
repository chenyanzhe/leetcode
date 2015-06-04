#include "ContainerWithMostWater.hpp"

#include <algorithm>
using namespace std;

int Solution::maxArea(vector<int>& height)
{
  if (height.size() < 2) return 0;

  int i = 0;
  int j = height.size() - 1;
  int area = min(height[i], height[j]) * (j - i);

  while (i < j) {
    if (height[i] < height[j]) {
      int k = i + 1;
      while (k < j) {
        if (height[k] > height[i] && min(height[k], height[j]) * (j - k) > area)
          area = min(height[k], height[j]) * (j - k);
        if (height[k] > height[j]) break;
        k++;
      }
      if (k == j) break;
      else i = k;
    } else {
      int k = j - 1;
      while (k > i) {
        if (height[k] > height[j] && min(height[k], height[i]) * (k - i) > area)
          area = min(height[k], height[i]) * (k - i);
        if (height[k] > height[i]) break;
        k--;
      }
      if (k == i) break;
      else j = k;
    }
  }
  return area;
}
