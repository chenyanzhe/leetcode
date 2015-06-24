#include "MultiplyStrings.hpp"

#include <vector>
using namespace std;

string MultiplyStrings::multiply(string num1, string num2)
{
  stripZeros(num1);
  stripZeros(num2);

  // some fast paths
  if (num1.empty() || num2.empty()) return "0";
  if (num1 == "1") return num2;
  if (num2 == "1") return num1;

  vector<string> dups(10, "");
  dups[1] = num1;
  string ret = "0";

  for (auto c : num2) {
    if (c == '0' || c == '1' || !dups[c - '0'].empty())
      continue;

    int carry = 0;
    int inum2 = c - '0';
    string result = "";

    for (int i = num1.size() - 1; i >= 0; i--) {
      int val = (num1[i] - '0') * inum2 + carry;
      carry = val / 10;
      result = to_string(val % 10) + result;
    }
    if (carry)
      result = to_string(carry) + result;

    dups[c - '0'] = result;
  }

  for (int i = num2.size() - 1, j = 0; i >= 0; i--, j++)
    ret = add(ret, dups[num2[i] - '0'] + string(j, '0'));

  return ret;
}

void MultiplyStrings::stripZeros(string& num)
{
  if (num.empty()) return;

  int i = -1;
  while (i + 1 < num.size() && num[i + 1] == '0')
    i++;
  num = num.substr(i + 1);
}

string MultiplyStrings::add(const string& num1, const string& num2)
{
  // add fast paths
  if (num1 == "0") return num2;
  if (num2 == "0") return num1;

  if (num1.size() > num2.size())
    return add(num2, num1);

  // num1.size() <= num2.size()
  int carry = 0;
  string result = "";
  int i = 0;
  int j = 0;
  for (i = num1.size() - 1, j = num2.size() - 1; i >= 0; i--, j--) {
    int val = num1[i] - '0' + num2[j] - '0' + carry;
    carry = val / 10;
    result = to_string(val % 10) + result;
  }
  for (; j >= 0; j--) {
    int val = num2[j] - '0' + carry;
    carry = val / 10;
    result = to_string(val % 10) + result;
  }

  if (carry)
    result = to_string(carry) + result;

  return result;
}
