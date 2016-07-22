#include "SerializeAndDeserializeBinaryTree.hpp"

string Codec::serialize(TreeNode *root) {
    ostringstream out;
    serializeHelper(root, out);
    return out.str();
}

TreeNode *Codec::deserialize(string data) {
    istringstream in(data);
    return deserialzeHelper(in);
}

void Codec::serializeHelper(TreeNode *root, ostringstream &out) {
    if (root != nullptr) {
        out << root->val << ' ';
        serializeHelper(root->left, out);
        serializeHelper(root->right, out);
    } else
        out << '#' << ' ';
}

TreeNode *Codec::deserialzeHelper(istringstream &in) {
    string val;
    in >> val;

    if (val == "#")
        return nullptr;

    TreeNode *root = new TreeNode(stoi(val));
    root->left = deserialzeHelper(in);
    root->right = deserialzeHelper(in);
    return root;
}
