#include "ImplementTrie.hpp"

TrieNode::TrieNode() {
    for (int i = 0; i < 26; i++)
        child[i] = nullptr;
    isWord = false;
}

TrieNode::~TrieNode() {
    for (int i = 0; i < 26; i++)
        if (child[i])
            delete child[i];
}

Trie::Trie() {
    root = new TrieNode();
}

Trie::~Trie() {
    delete root;
}

void Trie::insert(string word) {
    TrieNode *tail = root;
    for (auto c : word) {
        if (tail->child[c - 'a'] == nullptr) {
            tail->child[c - 'a'] = new TrieNode();
            tail = tail->child[c - 'a'];
        }
    }
    tail->isWord = true;
}

bool Trie::search(string word) {
    TrieNode *tail = root;
    for (auto c : word) {
        tail = tail->child[c - 'a'];
        if (tail == nullptr) return false;
    }
    return tail->isWord;
}

bool Trie::startsWith(string prefix) {
    TrieNode *tail = root;
    for (auto c : prefix) {
        tail = tail->child[c - 'a'];
        if (tail == nullptr) return false;
    }
    return true;
}
