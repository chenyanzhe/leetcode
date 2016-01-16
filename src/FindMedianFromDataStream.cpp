#include "FindMedianFromDataStream.hpp"

void MedianFinder::addNum(int num)
{
  small.push(num);
  large.push(-small.top());
  small.pop();

  if (small.size() < large.size()) {
    small.push(-large.top());
    large.pop();
  }
}

double MedianFinder::findMedian()
{
  return small.size() > large.size()
         ? small.top()
         : (small.top() - large.top()) / 2.0;
}