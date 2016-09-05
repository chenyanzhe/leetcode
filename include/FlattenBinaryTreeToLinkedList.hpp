#ifndef FLATTEN_BINARY_TREE_TO_LINKED_LIST_HPP_
#define FLATTEN_BINARY_TREE_TO_LINKED_LIST_HPP_

#include "TreeNode.hpp"

class FlattenBinaryTreeToLinkedList {
public:
    void flatten(TreeNode *root);

private:
    void flattenRec1(TreeNode *root);

    TreeNode *flattenRec2(TreeNode *root, TreeNode *tail);

    void flattenRec3(TreeNode *root, TreeNode *&prev);

    void flattenStack(TreeNode *root);
};

#endif // FLATTEN_BINARY_TREE_TO_LINKED_LIST_HPP_
