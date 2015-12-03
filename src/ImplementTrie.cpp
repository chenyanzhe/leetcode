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

bool Trie::search(string word)
{
    return search(root, word);
}

bool Trie::startsWith(string prefix)
{
    return startsWith(root, prefix);
}

void Trie::insert(TrieNode *root, string word)
{
    if (word.size() == 0) return;
    int idx = word[0] - 'a';
    if (root->children[idx] == NULL)
        root->children[idx] = new TrieNode();
    if (word.size() == 1)
        root->children[idx]->ending = true;
    else
        insert(root->children[idx], word.substr(1));
}

bool Trie::search(TrieNode *root, string word)
{
    if (word.size() == 0) return false;
    int idx = word[0] - 'a';
    if (root->children[idx] == NULL)
        return false;
    else if (word.size() == 1)
        return root->children[idx]->ending;
    else
        return search(root->children[idx], word.substr(1));
}

bool Trie::startsWith(TrieNode *root, string prefix)
{
    if (prefix.size() == 0) return false;
    int idx = prefix[0] - 'a';
    if (root->children[idx] == NULL)
        return false;
    else if (prefix.size() == 1)
        return true;
    else
        return startsWith(root->children[idx], prefix.substr(1));
}
