#ifndef SERIALIZE_AND_DESERIALIZE_BINARY_TREE_HPP_
#define SERIALIZE_AND_DESERIALIZE_BINARY_TREE_HPP_

#include "TreeNode.hpp"

#include <string>

using namespace std;

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root);

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data);

private:
    TreeNode *helper(string &data);

    int decode(string &data);
};

#endif // SERIALIZE_AND_DESERIALIZE_BINARY_TREE_HPP_
