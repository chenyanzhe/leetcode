#include "TrappingRainWater.hpp"

int TrappingRainWater::trap(vector<int>& height)
{
  int sz = height.size();

  if (sz <= 2)
    return 0;

  int max = height[0];
  int max_idx = 0;

  for (int i = 1; i < sz; i++)
    if (height[i] > max) {
      max = height[i];
      max_idx = i;
    }

  int result = 0;

  for (int i = 0, root = height[0]; i < max_idx; i++) {
    if (root < height[i])
      root = height[i];
    else
      result += (root - height[i]);
  }

  for (int i = sz - 1, root = height[sz - 1]; i > max_idx; i--) {
    if (root < height[i])
      root = height[i];
    else
      result += (root - height[i]);
  }

  return result;
}
