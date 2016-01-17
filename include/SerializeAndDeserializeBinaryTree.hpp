#ifndef SERIALIZE_AND_DESERIALIZE_BINARY_TREE_HPP_
#define SERIALIZE_AND_DESERIALIZE_BINARY_TREE_HPP_

#include <string>
#include <sstream>
#include "TreeNode.hpp"
using namespace std;

class Codec
{
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root);

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data);

private:
  TreeNode* fetch(istringstream& ss);
};

#endif // SERIALIZE_AND_DESERIALIZE_BINARY_TREE_HPP_