#ifndef UNIQUE_WORD_ABBREVIATION_HPP_
#define UNIQUE_WORD_ABBREVIATION_HPP_

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary);

    bool isUnique(string word);

private:
    unordered_map<string, string> lookup;
};

#endif // UNIQUE_WORD_ABBREVIATION_HPP_