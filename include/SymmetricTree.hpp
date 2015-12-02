#ifndef SYMMETRIC_TREE_HPP_
#define SYMMETRIC_TREE_HPP_

#include "TreeNode.hpp"

class SymmetricTree {
public:
	bool isSymmetric(TreeNode* root);
private:
	bool isSymmetric(TreeNode *l, TreeNode *r);
};

#endif // SYMMETRIC_TREE_HPP_
