#include "ClosestBinarySearchTreeValueII.hpp"

#include <stack>
#include <cmath>

using namespace std;

vector<int> ClosestBinarySearchTreeValueII::closestKValues(TreeNode *root, double target, int k) {
    vector<int> ret;
    stack<TreeNode *> s;
    TreeNode *current = root;

    while (!s.empty() || current) {
        if (current) {
            s.push(current);
            current = current->left;
        } else {
            current = s.top();
            s.pop();

            if (ret.size() < k)
                ret.push_back(current->val);
            else if (abs(current->val - target) < abs(ret[0] - target)) {
                ret.erase(ret.begin());
                ret.push_back(current->val);
            } else break;

            current = current->right;
        }
    }

    return ret;
}