#ifndef BINARY_TREE_INORDER_TRAVERSAL_HPP_
#define BINARY_TREE_INORDER_TRAVERSAL_HPP_

#include "TreeNode.hpp"

#include <vector>
using namespace std;

class BinaryTreeInorderTraversal {
private:
	vector<int> res;
public:
	vector<int> inorderTraversal(TreeNode* root);
};

#endif // BINARY_TREE_INORDER_TRAVERSAL_HPP_