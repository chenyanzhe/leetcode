#ifndef INTEGER_TO_ROMAN_HPP_
#define INTEGER_TO_ROMAN_HPP_

#include <string>
using namespace std;

class IntegerToRoman
{
public:
  string intToRoman(int num);
private:
  string digitToRoman(int digit, int level);
};

#endif // INTEGER_TO_ROMAN_HPP_
