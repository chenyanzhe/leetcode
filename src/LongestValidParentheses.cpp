#include "LongestValidParentheses.hpp"

#include <stack>
using namespace std;

int LongestValidParentheses::longestValidParentheses(string s)
{
  if (s.size() < 2) return 0;

  int ret = 0;
  for (int i = 0; i < s.size(); i++) {
    stack<char> checker;
    int len = 0;
    for (int j = i; j < s.size(); j++) {
      if (!checker.empty() && checker.top() == '(' && s[j] == ')') {
        checker.pop();
        len += 2;
      } else
        checker.push(s[j]);
    }
    ret = (len > ret) ? len : ret;
  }

  return ret;
}
