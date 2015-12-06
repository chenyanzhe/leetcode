#include "ImplementTrie.hpp"

TrieNode::TrieNode() : children(vector<TrieNode *>(26, nullptr)), isWord(false)
{}

TrieNode::~TrieNode()
{
    for (auto child : children)
        if (child != nullptr) delete child;
}

Trie::Trie()
{
    root = new TrieNode();
}

Trie::~Trie()
{
    delete root;
}

void Trie::insert(string word)
{
    TrieNode *now = root;
    for (int i = 0; i < word.size(); i++) {
        int idx = word[i] - 'a';
        if (now->children[idx] == nullptr)
            now->children[idx] = new TrieNode();
        now = now->children[idx];
    }
    now->isWord = true;
}

bool Trie::search(string word)
{
    return search(root, word.c_str());
}

bool Trie::startsWith(string prefix)
{
    return startsWith(root, prefix.c_str());
}

bool Trie::search(TrieNode *root, const char *head)
{
    if (root == nullptr) return false;
    if (*head == '\0') return root->isWord;

    int idx = *head - 'a';
    return search(root->children[idx], head + 1);
}

bool Trie::startsWith(TrieNode *root, const char *head)
{
    if (root == nullptr) return false;
    if (*head == '\0') return true;

    int idx = *head - 'a';
    return startsWith(root->children[idx], head + 1);
}
