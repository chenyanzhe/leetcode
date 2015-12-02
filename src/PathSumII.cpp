#include "PathSumII.hpp"

vector<vector<int>> PathSumII::pathSum(TreeNode* root, int sum)
{
	vector<int> path;

	pathSum(root, path, sum);

	return res;
}

void PathSumII::pathSum(TreeNode *root, vector<int> &path, int sum)
{
	if (root == nullptr) return;

	path.push_back(root->val);

	if (root->val == sum && root->left == nullptr && root->right == nullptr) {
		res.push_back(path);
	}

	pathSum(root->left, path, sum - root->val);
	pathSum(root->right, path, sum - root->val);

	path.pop_back();
}
