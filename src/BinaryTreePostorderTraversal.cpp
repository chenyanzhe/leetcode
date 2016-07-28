#include "BinaryTreePostorderTraversal.hpp"

#include <stack>
#include <unordered_map>

using namespace std;

vector<int> BinaryTreePostorderTraversal::postorderTraversal(TreeNode *root) {
    return postorderTraversal_Morris(root);
}

vector<int> BinaryTreePostorderTraversal::postorderTraversal_OneStack(
        TreeNode *root) {
    vector<int> ret;
    stack<TreeNode *> s;
    TreeNode *node = root;

    while (node || !s.empty()) {
        if (node) {
            s.push(node);
            node = node->left;
        } else {
            if (s.top()->right) {
                node = s.top()->right;
            } else {
                TreeNode *tmp;
                do {
                    tmp = s.top();
                    s.pop();
                    ret.push_back(tmp->val);
                } while (!s.empty() && s.top()->right == tmp);
            }
        }
    }

    return ret;
}

vector<int> BinaryTreePostorderTraversal::postorderTraversal_TwoStack(
        TreeNode *root) {
    vector<int> ret;
    stack<TreeNode *> s1;
    stack<TreeNode *> s2;

    if (root != nullptr) s1.push(root);

    while (!s1.empty()) {
        TreeNode *current = s1.top();
        s1.pop();
        s2.push(current);

        if (current->left != nullptr)
            s1.push(current->left);

        if (current->right != nullptr)
            s1.push(current->right);
    }

    while (!s2.empty()) {
        TreeNode *current = s2.top();
        s2.pop();
        ret.push_back(current->val);
    }

    return ret;
}

// reverse the tree nodes 'from' -> 'to'
void BinaryTreePostorderTraversal::reverse(TreeNode *from, TreeNode *to) {
    if (from == to) return;

    TreeNode *x = from, *y = from->right, *z;

    while (true) {
        z = y->right;
        y->right = x;
        x = y;
        y = z;
        if (x == to)
            break;
    }
}

// visit the tree nodes 'from' -> 'to' reversely
void BinaryTreePostorderTraversal::visitReverse(TreeNode *from, TreeNode *to, vector<int> &ret) {
    reverse(from, to);

    TreeNode *p = to;
    while (true) {
        ret.push_back(p->val);
        if (p == from)
            break;
        p = p->right;
    }

    reverse(to, from);
}

vector<int> BinaryTreePostorderTraversal::postorderTraversal_Morris(TreeNode *root) {
    TreeNode dump(0);
    dump.left = root;
    TreeNode *cur = &dump, *prev = nullptr;
    vector<int> ret;

    while (cur) {
        if (!cur->left) {
            cur = cur->right;
        } else {
            prev = cur->left;

            while (prev->right && prev->right != cur)
                prev = prev->right;

            if (!prev->right) {
                prev->right = cur;
                cur = cur->left;
            } else {
                visitReverse(cur->left, prev, ret);
                prev->right = nullptr;
                cur = cur->right;
            }
        }
    }

    return ret;
}

vector<int> BinaryTreePostorderTraversal::postorderTraversal_HashTable(TreeNode *root) {
    vector<int> ret;
    unordered_map<TreeNode *, int> action;
    stack<TreeNode *> s;

    if (root == nullptr)
        return ret;

    s.push(root);
    action[root] = 1;
    if (root->right) {
        s.push(root->right);
        action[root->right] = 0;
    }
    if (root->left) {
        s.push(root->left);
        action[root->left] = 0;
    }

    while (!s.empty()) {
        TreeNode *node = s.top();
        s.pop();
        if (action[node] == 1) {
            ret.push_back(node->val);
            action.erase(node);
        } else {
            s.push(node);
            action[node] = 1;
            if (node->right) {
                s.push(node->right);
                action[node->right] = 0;
            }
            if (node->left) {
                s.push(node->left);
                action[node->left] = 0;
            }
        }
    }

    return ret;
}

