#ifndef VALIDATE_BINARY_SEARCH_TREE_HPP_
#define VALIDATE_BINARY_SEARCH_TREE_HPP_

#include "TreeNode.hpp"

class ValidateBinarySearchTree {
public:
	bool isValidBST(TreeNode* root);
private:
	int minNodeVal(TreeNode* root);
	int maxNodeVal(TreeNode* root);
};

#endif // VALIDATE_BINARY_SEARCH_TREE_HPP_
