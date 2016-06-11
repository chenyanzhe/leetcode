#ifndef BURST_BALLOONS_HPP_
#define BURST_BALLOONS_HPP_

#include <vector>
using namespace std;

class BurstBalloons
{
public:
  int maxCoins(vector<int>& nums);
private:
  int getCoins(vector<int>& nums, int index);
  int getCoins(vector<vector<int>>& dp, int i, int j);
};

#endif // BURST_BALLOONS_HPP_
