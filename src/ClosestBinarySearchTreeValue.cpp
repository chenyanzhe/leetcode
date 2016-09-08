#include "ClosestBinarySearchTreeValue.hpp"

#include <cmath>

using namespace std;

int ClosestBinarySearchTreeValue::closestValue(TreeNode *root, double target) {
    int closest = root->val;
    while (root) {
        if (abs(root->val - target) < abs(closest - target))
            closest = root->val;
        root = root->val < target ? root->right : root->left;
    }
    return closest;
}