#ifndef RECOVER_BINARY_SEARCH_TREE_HPP_
#define RECOVER_BINARY_SEARCH_TREE_HPP_

#include "TreeNode.hpp"

#include <vector>
using namespace std;

class RecoverBinarySearchTree
{
private:
  vector<TreeNode*> nodePtrs;
  vector<int> nodeVals;

public:
  void recoverTree(TreeNode* root);
private:
  void inOrderTraversal(TreeNode* root);
};

#endif // RECOVER_BINARY_SEARCH_TREE_HPP_
