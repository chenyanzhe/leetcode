#ifndef TARGET_SUM_HPP_
#define TARGET_SUM_HPP_

#include <vector>

using namespace std;

class TargetSum {
public:
    int findTargetSumWays(vector<int>& nums, int S);

private:
    void dfs(vector<int>& nums, int S, int depth, int local, int& global);
};

#endif // TARGET_SUM_HPP_
