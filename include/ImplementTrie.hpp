#ifndef IMPLEMENT_TRIE_HPP_
#define IMPLEMENT_TRIE_HPP_

#include <string>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode();
    TrieNode **children;
    bool ending;
};

class Trie {
public:
    Trie();

    // Inserts a word into the trie.
    void insert(string word);

    // Returns if the word is in the trie.
    bool search(string word);

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix);

private:
    TrieNode* root;

    void insert(TrieNode *root, string word);

    bool search(TrieNode *root, string word);

    bool startsWith(TrieNode *root, string prefix);
};

#endif // IMPLEMENT_TRIE_HPP_
