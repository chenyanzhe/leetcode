#include "TrappingRainWater.hpp"

int TrappingRainWater::trap(vector<int>& height)
{
  int width = height.size();
  if (width == 0) return 0;

  int ret = 0;
  vector<int> dp(width, 0);

  int max = 0;
  for (int i = 0; i < width; i++) {
    dp[i] = max;
    max = (height[i] > max) ? height[i] : max;
  }

  max = 0;
  for (int i = width - 1; i >= 0; i--) {
    int h = (dp[i] < max) ? dp[i] : max;
    ret += (h > height[i]) ? h - height[i] : 0;
    max = (height[i] > max) ? height[i] : max;
  }

  return ret;
}
