#include "SerializeAndDeserializeBinaryTree.hpp"

#include <vector>
#include <queue>
using namespace std;

string Codec::serialize(TreeNode* root)
{
  vector<string> vec;
  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode* node = q.front();

    if (node == nullptr) {
      vec.push_back("null");
    } else {
      vec.push_back(to_string(node->val));
      q.push(node->left);
      q.push(node->right);
    }

    q.pop();
  }

  string ret = vec[0];

  if (vec.size() == 1) {
    return ret;
  } else {
    for (int i = 1; i < vec.size(); i++) {
      ret += "," + vec[i];
    }
  }

  return ret;
}

TreeNode* Codec::deserialize(string data)
{
  istringstream ss(data);
  string token;
  queue<TreeNode*> q;
  TreeNode* root = fetch(ss);
  q.push(root);

  while (!q.empty()) {
    TreeNode* node = q.front();

    if (node != nullptr) {
      node->left = fetch(ss);
      node->right = fetch(ss);
      q.push(node->left);
      q.push(node->right);
    }

    q.pop();
  }

  return root;
}

TreeNode* Codec::fetch(istringstream& ss)
{
  string token;

  if (getline(ss, token, ',') && token != "null") {
    return new TreeNode(stoi(token));
  } else {
    return nullptr;
  }
}