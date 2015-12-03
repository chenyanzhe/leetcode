#ifndef IMPLEMENT_TRIE_HPP_
#define IMPLEMENT_TRIE_HPP_

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
    void insert(string word) {
        insert(root, word);
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        return search(root, word);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return startsWith(root, prefix);
    }

private:
    TrieNode* root;
    
    void insert(TrieNode *root, string word) {
        if (word.size() == 0) return;
        int idx = word[0] - 'a';
        if (root->children[idx] == NULL)
            root->children[idx] = new TrieNode();
        if (word.size() == 1)
            root->children[idx]->ending = true;
        else
            insert(root->children[idx], word.substr(1));
    }
    
    bool search(TrieNode *root, string word) {
        if (word.size() == 0) return false;
        int idx = word[0] - 'a';
        if (root->children[idx] == NULL)
            return false;
        else if (word.size() == 1)
            return root->children[idx]->ending;
        else
            return search(root->children[idx], word.substr(1));
    }
    
    bool startsWith(TrieNode *root, string prefix) {
        if (prefix.size() == 0) return false;
        int idx = prefix[0] - 'a';
        if (root->children[idx] == NULL)
            return false;
        else if (prefix.size() == 1)
            return true;
        else
            return startsWith(root->children[idx], prefix.substr(1));
    }
};

#endif // IMPLEMENT_TRIE_HPP_