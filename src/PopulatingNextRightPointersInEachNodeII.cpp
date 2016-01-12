#include "PopulatingNextRightPointersInEachNodeII.hpp"

#include <queue>
using namespace std;

void PopulatingNextRightPointersInEachNodeII::connect(TreeLinkNode* root)
{
  if (root == nullptr) {
    return;
  }

  queue<TreeLinkNode*> q;
  q.push(root);

  while (!q.empty()) {
    int k = q.size(); // number of nodes in this level

    for (int i = 0; i < k; i++) {
      TreeLinkNode* front = q.front();
      q.pop();

      if (i + 1 < k) {
        front->next = q.front();
      }

      if (front->left != nullptr) {
        q.push(front->left);
      }

      if (front->right != nullptr) {
        q.push(front->right);
      }
    }
  }
}
