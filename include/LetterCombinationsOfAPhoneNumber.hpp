#ifndef LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_HPP_
#define LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_HPP_

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class LetterCombinationsOfAPhoneNumber {
private:
    unordered_map<int, string> dict{
            {0, ""},
            {1, ""},
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
    };

public:
    vector<string> letterCombinations(string digits);

private:
    void backtrack(string &digits, int begin, string &current, vector<string> &result);
};

#endif // LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_HPP_
