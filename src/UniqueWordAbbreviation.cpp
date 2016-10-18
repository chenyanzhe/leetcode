#include "UniqueWordAbbreviation.hpp"

ValidWordAbbr::ValidWordAbbr(vector<string> &dictionary) {
    for (auto &word : dictionary) {
        if (word.size() <= 2) continue;
        string abbr = word[0] + to_string(word.size() - 2) + word[word.size() - 1];
        if (lookup.find(abbr) != lookup.end() && lookup[abbr] != word)
            lookup[abbr] = ""; // mark as invalid
        else
            lookup[abbr] = word;
    }
}

bool ValidWordAbbr::isUnique(string word) {
    if (word.size() <= 2) return true;
    string abbr = word[0] + to_string(word.size() - 2) + word[word.size() - 1];
    if (lookup.find(abbr) == lookup.end()) return true;
    return lookup[abbr] == word;
}
