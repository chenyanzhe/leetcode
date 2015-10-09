#include "BinaryTreeZigzagLevelOrderTraversal.hpp"

#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> BinaryTreeZigzagLevelOrderTraversal::zigzagLevelOrder(TreeNode* root)
{
	queue<TreeNode *> q;
	vector<vector<int>> ret;

	if (root == nullptr) return ret;

	q.push(root);
	ret.push_back({});
	
	int curLevel = 1;
	int nextLevel = 0;

	TreeNode *top;

	while (!q.empty()) {
		if (curLevel == 0) {
			ret.push_back({});
			curLevel = nextLevel;
			nextLevel = 0;
		}

		top = q.front();
		q.pop();
		curLevel--;

		if (top->left != nullptr) {
			q.push(top->left);
			nextLevel++;
		}
		if (top->right != nullptr) {
			q.push(top->right);
			nextLevel++;
		}

		ret.back().push_back(top->val);
	}

	bool r = false;
	for (int i = 0; i < ret.size(); i++, r = !r)
		if (r) reverse(ret[i].begin(), ret[i].end());
	
	return ret;
}