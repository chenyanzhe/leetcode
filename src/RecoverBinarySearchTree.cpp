#include "RecoverBinarySearchTree.hpp"

void RecoverBinarySearchTree::recoverTree(TreeNode *root) {
    TreeNode *prev = nullptr, *first = nullptr, *second = nullptr;
    findSegments(root, prev, first, second);
    swap(first->val, second->val);
}

void RecoverBinarySearchTree::findSegments(TreeNode *root, TreeNode *&prev,
                                           TreeNode *&first, TreeNode *&second) {
    if (root == nullptr)
        return;

    findSegments(root->left, prev, first, second);

    if (prev != nullptr && prev->val > root->val) {
        if (first == nullptr)
            first = prev;

        second = root;
    }

    prev = root;
    findSegments(root->right, prev, first, second);
}

void RecoverBinarySearchTree::detect(pair<TreeNode *, TreeNode *> &broken, TreeNode *prev, TreeNode *current) {
    if (prev && prev->val > current->val) {
        if (!broken.first)
            broken.first = prev;
        broken.second = current;
    }
}

void RecoverBinarySearchTree::recoverTree_Morris(TreeNode *root) {
    pair<TreeNode *, TreeNode *> broken;
    TreeNode *current = root;
    TreeNode *prev = nullptr;

    while (current != nullptr) {
        if (current->left == nullptr) {
            detect(broken, prev, current);
            prev = current;
            current = current->right;
        } else {
            TreeNode *pred = current->left;

            while (pred->right != nullptr && pred->right != current)
                pred = pred->right;

            if (pred->right == nullptr) {
                pred->right = current;
                current = current->left;
            } else {
                detect(broken, prev, current);
                prev = current;
                pred->right = nullptr;
                current = current->right;
            }
        }
    }

    swap(broken.first->val, broken.second->val);
}