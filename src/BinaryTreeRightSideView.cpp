#include "BinaryTreeRightSideView.hpp"

#include <queue>
using namespace std;

vector<int> BinaryTreeRightSideView::rightSideView(TreeNode* root)
{
    vector<int> result;
    bfs(root, result);
    return result;
}

void BinaryTreeRightSideView::bfs(TreeNode* root, vector<int>& result)
{
    if (root == nullptr) return;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        int num = q.size(); // number of nodes at this level
        for (int i = 0; i < num; i++) {
            TreeNode *n = q.front();
            q.pop();
            if (n->left != nullptr) q.push(n->left);
            if (n->right != nullptr) q.push(n->right);
            if (i == num - 1) result.push_back(n->val);
        }
    }
}
