#include "ExcelSheetColumnNumber.hpp"

int ExcelSheetColumnNumber::titleToNumber(string s)
{
  int result = 0;

  for (auto c : s) {
    result = result * 26 + (c - 'A' + 1);
  }

  return result;
}
