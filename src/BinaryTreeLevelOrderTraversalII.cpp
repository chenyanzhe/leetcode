#include "BinaryTreeLevelOrderTraversalII.hpp"

#include <queue>

using namespace std;

vector<vector<int>> BinaryTreeLevelOrderTraversalII::levelOrderBottom(
        TreeNode *root) {
    vector<vector<int>> ret;
    queue<TreeNode *> q;

    if (root != nullptr) q.push(root);

    while (!q.empty()) {
        int n = q.size();
        vector<int> newlevel(n);

        for (int i = 0; i < n; i++) {
            TreeNode *current = q.front();
            q.pop();
            newlevel[i] = current->val;

            if (current->left != nullptr)
                q.push(current->left);

            if (current->right != nullptr)
                q.push(current->right);
        }

        ret.push_back(newlevel);
    }

    reverse(ret.begin(), ret.end());
    return ret;
}
