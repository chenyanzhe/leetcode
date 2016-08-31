#include "ImplementTrie.hpp"

TrieNode::TrieNode() {
    for (int i = 0; i < 26; i++)
        children[i] = nullptr;
    isWord = false;
}

TrieNode::~TrieNode() {
    for (int i = 0; i < 26; i++)
        if (children[i])
            delete children[i];
}

Trie::Trie() {
    root = new TrieNode();
}

Trie::~Trie() {
    delete root;
}

void Trie::insert(string word) {
    TrieNode *now = root;

    for (auto c : word) {
        if (now->children[c - 'a'] == nullptr)
            now->children[c - 'a'] = new TrieNode();
        now = now->children[c - 'a'];
    }

    now->isWord = true;
}

bool Trie::search(string word) {
    return search(root, word.c_str());
}

bool Trie::startsWith(string prefix) {
    return startsWith(root, prefix.c_str());
}

bool Trie::search(TrieNode *root, const char *head) {
    if (root == nullptr)
        return false;

    if (*head == '\0')
        return root->isWord;

    int idx = *head - 'a';
    return search(root->children[idx], head + 1);
}

bool Trie::startsWith(TrieNode *root, const char *head) {
    if (root == nullptr)
        return false;

    if (*head == '\0')
        return true;

    int idx = *head - 'a';
    return startsWith(root->children[idx], head + 1);
}
