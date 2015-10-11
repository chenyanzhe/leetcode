#include "BalancedBinaryTree.hpp"

bool BalancedBinaryTree::isBalanced(TreeNode* root)
{
	if (root == nullptr) return true;

	int leftHeight = tree_height(root->left);
	int rightHeight = tree_height(root->right);

	int delta = leftHeight - rightHeight;

	bool leftIsBalanced = isBalanced(root->left);
	bool rightIsBalanced = isBalanced(root->right);

	return leftIsBalanced && rightIsBalanced && -1 <= delta && delta <= 1;
}