#include "BinaryTreeLevelOrderTraversal.hpp"

#include <queue>
using namespace std;

vector<vector<int>> BinaryTreeLevelOrderTraversal::levelOrder(TreeNode* root)
{
  /*
   * Create a tree like this:
   *     3
   *    / \
   *   9   20
   *       / \
   *      15  7
   */
  // push 3 (level 1), pop 3 push 9 push 20 (level 2), pop 9, pop 20 push 15 push 7(level 3), pop 15, pop 7
  vector<vector<int>> ret;

  if (root == nullptr) {
    return ret;
  }

  queue<TreeNode*> nodes;
  nodes.push(root);
  ret.push_back({});
  int level = 0;     // this level index
  int thisLevel = 1; // number of nodes at this level
  int nextLevel = 0; // number of nodes at next level

  while (!nodes.empty()) {
    TreeNode* front = nodes.front();

    if (thisLevel > 0) {
      ret[level].push_back(front->val);
      thisLevel--;
    } else {
      thisLevel = nextLevel;
      nextLevel = 0;
      level++;
      ret.push_back({});
      ret[level].push_back(front->val);
      thisLevel--;
    }

    if (front->left != nullptr) {
      nodes.push(front->left);
      nextLevel++;
    }

    if (front->right != nullptr) {
      nodes.push(front->right);
      nextLevel++;
    }

    nodes.pop();
  }

  return ret;
}
