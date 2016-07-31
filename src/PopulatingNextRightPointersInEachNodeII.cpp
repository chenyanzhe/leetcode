#include "PopulatingNextRightPointersInEachNodeII.hpp"

void PopulatingNextRightPointersInEachNodeII::connect(TreeLinkNode *root) {
    connect_Recursive(root);
}

void PopulatingNextRightPointersInEachNodeII::connect_Recursive(TreeLinkNode *root) {
    if (root == nullptr) return;

    TreeLinkNode dummy(0);
    for (TreeLinkNode *curr = root, *prev = &dummy; curr; curr = curr->next) {
        if (curr->left) {
            prev->next = curr->left;
            prev = curr->left;
        }
        if (curr->right) {
            prev->next = curr->right;
            prev = curr->right;
        }
    }
    connect_Recursive(dummy.next);
}

void PopulatingNextRightPointersInEachNodeII::connect_Iterative(TreeLinkNode *root) {
    while (root) {
        TreeLinkNode *next = nullptr; // the first node of the next level
        TreeLinkNode *prev = nullptr; // previous node on the same level
        for (; root; root = root->next) {
            if (!next) next = root->left ? root->left : root->right;

            if (root->left) {
                if (prev) prev->next = root->left;
                prev = root->left;
            }
            if (root->right) {
                if (prev) prev->next = root->right;
                prev = root->right;
            }
        }
        root = next;
    }
}
