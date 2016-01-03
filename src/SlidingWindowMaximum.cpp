#include "SlidingWindowMaximum.hpp"

#include <deque>
using namespace std;

vector<int> SlidingWindowMaximum::maxSlidingWindow(vector<int>& nums, int k)
{
  vector<int> ret;
  deque<int> dq;
  
  for (int i = 0; i < nums.size(); i++) {
    if (!dq.empty() && dq.front() == i - k)
      dq.pop_front();
    while (!dq.empty() && nums[dq.back()] < nums[i])
      dq.pop_back();
    dq.push_back(i);
    if (i >= k - 1) ret.push_back(nums[dq.front()]);
  }
  
  return ret;
}