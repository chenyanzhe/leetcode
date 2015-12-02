#include "ConstructBinaryTreeFromPreorderAndInorderTraversal.hpp"

TreeNode* ConstructBinaryTreeFromPreorderAndInorderTraversal::
	buildTree(vector<int>& preorder, vector<int>& inorder)
{
	preIndex = 0;
	return buildTree(preorder, inorder, 0, inorder.size() - 1);
}

TreeNode* ConstructBinaryTreeFromPreorderAndInorderTraversal::
	buildTree(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd)
{
	if (inStart > inEnd) return nullptr;

	TreeNode *root = new TreeNode(preorder[preIndex++]);

	if (inStart == inEnd) return root;

	// find root in inorder
	int mid = inStart;
	while (mid <= inEnd && inorder[mid] != root->val)
		mid++;

	root->left = buildTree(preorder, inorder, inStart, mid - 1);
	root->right = buildTree(preorder, inorder, mid + 1, inEnd);

	return root;
}
