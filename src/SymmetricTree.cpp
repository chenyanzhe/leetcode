#include "SymmetricTree.hpp"

bool SymmetricTree::isSymmetric(TreeNode* root)
{
	if (root == nullptr) return true;

	return isSymmetric(root->left, root->right);
}

bool SymmetricTree::isSymmetric(TreeNode *l, TreeNode *r)
{
	if (l == nullptr && r == nullptr) return true;
	if (l == nullptr || r == nullptr) return false;

	return (l->val == r->val) && isSymmetric(l->left, r->right) && isSymmetric(l->right, r->left);
}