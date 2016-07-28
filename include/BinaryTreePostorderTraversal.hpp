#ifndef BINARY_TREE_POSTORDER_TRAVERSAL_HPP_
#define BINARY_TREE_POSTORDER_TRAVERSAL_HPP_

#include "TreeNode.hpp"

#include <vector>

using namespace std;

class BinaryTreePostorderTraversal {
public:
    vector<int> postorderTraversal(TreeNode *root);

private:
    vector<int> postorderTraversal_TwoStack(TreeNode *root);

    vector<int> postorderTraversal_OneStack(TreeNode *root);

    vector<int> postorderTraversal_Morris(TreeNode *root);

    void reverse(TreeNode *from, TreeNode *to);

    void visitReverse(TreeNode *from, TreeNode *to, vector<int> &ret);

    vector<int> postorderTraversal_HashTable(TreeNode *root);
};

#endif // BINARY_TREE_POSTORDER_TRAVERSAL_HPP_

