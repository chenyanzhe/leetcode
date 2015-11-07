#ifndef VALID_PARENTHESES_HPP_
#define VALID_PARENTHESES_HPP_

#include <string>
using namespace std;

class ValidParentheses {
public:
  bool isValid(string s);
private:
  bool isPair(char a, char b);
};

#endif // VALID_PARENTHESES_HPP_
