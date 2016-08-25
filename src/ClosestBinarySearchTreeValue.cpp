#include "ClosestBinarySearchTreeValue.hpp"

#include <cmath>

using namespace std;

int ClosestBinarySearchTreeValue::closestValue(TreeNode *root, double target) {
    int a = root->val;
    auto kid = target < a ? root->left : root->right;
    if (!kid) return a;
    int b = closestValue(kid, target);
    return abs(a - target) < abs(b - target) ? a : b;
}