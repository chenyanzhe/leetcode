#ifndef HOUSE_ROBBER_III_HPP_
#define HOUSE_ROBBER_III_HPP_

#include "TreeNode.hpp"

#include <vector>
#include <unordered_map>

using namespace std;

class HouseRobberIII {
public:
    int rob(TreeNode *root);

private:
    int robMem(TreeNode *root, unordered_map<TreeNode *, int> &mem);

    vector<int> robGreedy(TreeNode *root);
};

#endif // HOUSE_ROBBER_III_HPP_
