#include "SerializeAndDeserializeBinaryTree.hpp"

string Codec::serialize(TreeNode *root) {
    if (root == nullptr) return "#";
    return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
}

TreeNode *Codec::deserialize(string data) {
    return helper(data);
}

TreeNode *Codec::helper(string &data) {
    if (data[0] == '#') {
        if (data.size() > 1) data = data.substr(2);
        return nullptr;
    } else {
        TreeNode *root = new TreeNode(decode(data));
        root->left = helper(data);
        root->right = helper(data);
        return root;
    }
}

int Codec::decode(string &data) {
    int pos = data.find(',');
    int val = stoi(data.substr(0, pos));
    data = data.substr(pos + 1);
    return val;
}
