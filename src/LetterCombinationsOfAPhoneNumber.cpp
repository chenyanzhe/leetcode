#include "LetterCombinationsOfAPhoneNumber.hpp"

const vector<vector<char>> LetterCombinationsOfAPhoneNumber::keyMap = {
  {' '}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'},
  {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'},
  {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}
};

vector<string> LetterCombinationsOfAPhoneNumber::letterCombinations(
  string digits)
{
  vector<string> ret;

  if (digits.size() == 0) {
    return ret;
  } else if (digits.size() == 1) {
    for (auto c : keyMap[digits[0] - '0']) {
      ret.push_back(string(1, c));
    }

    return ret;
  } else {
    vector<string> tails = letterCombinations(digits.substr(1));

    for (auto c : keyMap[digits[0] - '0']) {
      for (auto t : tails) {
        ret.push_back(string(1, c) + t);
      }
    }

    return ret;
  }
}
