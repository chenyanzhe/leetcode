#ifndef ADD_AND_SEARCH_WORD_HPP_
#define ADD_AND_SEARCH_WORD_HPP_

#include <string>
#include <vector>

using namespace std;

class WordTrieNode {
public:
    WordTrieNode();

    ~WordTrieNode();

    vector<WordTrieNode *> children;
    bool isWord;
};

class WordDictionary {
public:
    WordDictionary();

    ~WordDictionary();

    // Adds a word into the data structure.
    void addWord(string word);

    bool search(string word);

private:
    WordTrieNode *root;

    bool search(WordTrieNode *root, const char *head);
};

#endif // ADD_AND_SEARCH_WORD_HPP_
