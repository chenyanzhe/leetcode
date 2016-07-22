#ifndef TREE_NODE_HPP_
#define TREE_NODE_HPP_

#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

int tree_height(TreeNode *root);

string tree_serialize(TreeNode *root);

void tree_free(TreeNode *root);

#endif // TREE_NODE_HPP_
