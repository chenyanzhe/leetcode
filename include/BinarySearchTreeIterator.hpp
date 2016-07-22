#ifndef BINARY_SEARCH_TREE_ITERATOR_HPP_
#define BINARY_SEARCH_TREE_ITERATOR_HPP_

#include "TreeNode.hpp"
#include <stack>

using namespace std;

class BSTIterator {
public:
    BSTIterator(TreeNode *root);

    /** @return whether we have a next smallest number */
    bool hasNext();

    /** @return the next smallest number */
    int next();

private:
    stack<TreeNode *> s;
};

#endif // BINARY_SEARCH_TREE_ITERATOR_HPP_
