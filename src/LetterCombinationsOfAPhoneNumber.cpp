#include "LetterCombinationsOfAPhoneNumber.hpp"

vector<string> LetterCombinationsOfAPhoneNumber::letterCombinations(string digits) {
    vector<string> result;
    if (digits.empty()) return result;

    string current;
    backtrack(digits, 0, current, result);
    return result;
}

void LetterCombinationsOfAPhoneNumber::backtrack(string &digits, int begin, string &current, vector<string> &result) {
    if (begin >= digits.size()) {
        result.push_back(current);
        return;
    }
    for (auto c : dict[digits[begin] - '0']) {
        current.push_back(c);
        backtrack(digits, begin + 1, current, result);
        current.pop_back();
    }
}
