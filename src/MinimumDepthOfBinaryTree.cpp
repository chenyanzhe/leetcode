#include "MinimumDepthOfBinaryTree.hpp"

#include <queue>
using namespace std;

int MinimumDepthOfBinaryTree::minDepth(TreeNode* root)
{
	if (root == nullptr) return 0;

	queue<TreeNode *> q;
	q.push(root);
	int depth = 0;

	while (!q.empty()) {
		depth++;		  // scanning level `depth` now
		int k = q.size(); // number of nodes in level `depth`
		for (int i = 0; i < k; i++) {
			TreeNode *front = q.front();
			q.pop();
			if (front->left == nullptr && front->right == nullptr) {
				// we have reach the leaf node
				return depth;
			}
			if (front->left != nullptr) q.push(front->left);
			if (front->right != nullptr) q.push(front->right);
		}
	}

	return depth;
}
