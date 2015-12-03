#include "ImplementTrie.hpp"

TrieNode::TrieNode()
{
    children = new TrieNode*[26];
    for (int i = 0; i < 26; i++)
        children[i] = NULL;
    ending = false;
}

Trie::Trie()
{
    root = new TrieNode();
}

void Trie::insert(string word)
{
    insert(root, word);
}