#include "ConstructBinaryTreeFromInorderAndPostorderTraversal.hpp"

TreeNode* ConstructBinaryTreeFromInorderAndPostorderTraversal::
	buildTree(vector<int>& inorder, vector<int>& postorder)
{
	postIndex = postorder.size() - 1;
	return buildTree(inorder, postorder, 0, inorder.size() - 1);
}

TreeNode* ConstructBinaryTreeFromInorderAndPostorderTraversal::
	buildTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd)
{
	if (inStart > inEnd) return nullptr;

	TreeNode *root = new TreeNode(postorder[postIndex--]);

	if (inStart == inEnd) return root;

	// find root in inorder
	int mid = inStart;
	while (mid <= inEnd && inorder[mid] != root->val)
		mid++;

	root->right = buildTree(inorder, postorder, mid + 1, inEnd);
	root->left = buildTree(inorder, postorder, inStart, mid - 1);

	return root;
}