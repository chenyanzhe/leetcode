#include "PopulatingNextRightPointersInEachNode.hpp"

void PopulatingNextRightPointersInEachNode::connect(TreeLinkNode *root) {
    connect_Recursive(root, nullptr);
}

void PopulatingNextRightPointersInEachNode::connect_Iterative(TreeLinkNode *root) {
    if (root == nullptr) return;

    TreeLinkNode *leftMost = root;

    while (leftMost != nullptr && leftMost->left != nullptr) {
        TreeLinkNode *current = leftMost;

        while (current != nullptr) {
            current->left->next = current->right;
            current->right->next = current->next ? current->next->left : nullptr;
            current = current->next;
        }

        leftMost = leftMost->left;
    }
}

void PopulatingNextRightPointersInEachNode::connect_Recursive(TreeLinkNode *root, TreeLinkNode *sibling) {
    if (root == nullptr) return;

    root->next = sibling;

    connect_Recursive(root->left, root->right);

    if (sibling) {
        connect_Recursive(root->right, sibling->left);
    } else {
        connect_Recursive(root->right, nullptr);
    }
}
