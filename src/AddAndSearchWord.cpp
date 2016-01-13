#include "AddAndSearchWord.hpp"

WordTrieNode::WordTrieNode() : children(vector<WordTrieNode * >(26, nullptr)),
  isWord(false)
{
}

WordTrieNode::~WordTrieNode()
{
  for (auto child : children)
    if (child != nullptr) {
      delete child;
    }
}

WordDictionary::WordDictionary()
{
  root = new WordTrieNode();
}

WordDictionary::~WordDictionary()
{
  delete root;
}

void WordDictionary::addWord(string word)
{
  WordTrieNode* now = root;

  for (int i = 0; i < word.size(); i++) {
    int idx = word[i] - 'a';

    if (now->children[idx] == nullptr) {
      now->children[idx] = new WordTrieNode();
    }

    now = now->children[idx];
  }

  now->isWord = true;
}

bool WordDictionary::search(string word)
{
  return search(root, word.c_str());
}

bool WordDictionary::search(WordTrieNode* root, const char* head)
{
  if (root == nullptr) {
    return false;
  }

  if (*head == '\0') {
    return root->isWord;
  }

  if (*head != '.') {
    int idx = *head - 'a';
    return search(root->children[idx], head + 1);
  } else {
    for (int i = 0; i < 26; i++)
      if (search(root->children[i], head + 1)) {
        return true;
      }

    return false;
  }
}
