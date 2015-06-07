#ifndef LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_HPP_
#define LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_HPP_

#include <string>
#include <vector>
using namespace std;

class LetterCombinationsOfAPhoneNumber {
public:
  vector<string> letterCombinations(string digits);
private:
  static const vector<vector<char> > keyMap;
};

#endif // LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_HPP_
