#include "BinaryTreeInorderTraversal.hpp"

vector<int> BinaryTreeInorderTraversal::inorderTraversal(TreeNode* root)
{
	if (root != nullptr) {
		inorderTraversal(root->left);
		res.push_back(root->val);
		inorderTraversal(root->right);
	}
	return res;
}
