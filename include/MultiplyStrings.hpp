#ifndef MULTIPLY_STRINGS_HPP_
#define MULTIPLY_STRINGS_HPP_

#include <string>
using namespace std;

class MultiplyStrings
{
public:
  string multiply(string num1, string num2);
private:
  string add(const string& num1, const string& num2);
  void stripZeros(string& num);
};

#endif // MULTIPLY_STRINGS_HPP_
