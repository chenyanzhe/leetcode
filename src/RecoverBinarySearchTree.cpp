#include "RecoverBinarySearchTree.hpp"

#include <algorithm>
using namespace std;

void RecoverBinarySearchTree::recoverTree(TreeNode* root)
{
	inOrderTraversal(root);
	sort(nodeVals.begin(), nodeVals.end());
	for (int i = 0; i < nodePtrs.size(); i++)
		nodePtrs[i]->val = nodeVals[i];
}

void RecoverBinarySearchTree::inOrderTraversal(TreeNode* root)
{
	if (root == nullptr) return;
	inOrderTraversal(root->left);
	nodePtrs.push_back(root);
	nodeVals.push_back(root->val);
	inOrderTraversal(root->right);
}
