#include "ValidPalindrome.hpp"

#include <cctype>
using namespace std;

bool ValidPalindrome::isPalindrome(string s)
{
  auto preprocess = [&](const string & s) {
    string result;

    for (auto c : s)
      if (isalnum(c))
        result += tolower(c);

    return result;
  };
  string input = preprocess(s);
  int i = 0;
  int j = input.size() - 1;

  while (i < j && input[i] == input[j]) {
    i++;
    j--;
  }

  return i >= j;
}
