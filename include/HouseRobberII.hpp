#ifndef HOUSE_ROBBER_II_HPP_
#define HOUSE_ROBBER_II_HPP_

#include <vector>

using namespace std;

class HouseRobberII {
public:
    int rob(vector<int> &nums);

private:
    int helper(vector<int> &nums, int a, int b);
};

#endif // HOUSE_ROBBER_II_HPP_
