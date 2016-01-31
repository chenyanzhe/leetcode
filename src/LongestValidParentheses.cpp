#include "LongestValidParentheses.hpp"

#include <stack>
using namespace std;

int LongestValidParentheses::longestValidParentheses(string s)
{
  int ret = 0;
  stack<int> stk;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ')' && !stk.empty() && s[stk.top()] == '(') {
      stk.pop();

      if (stk.empty()) {
        ret = i + 1;
      } else {
        ret = max(ret, i - stk.top());
      }
    } else {
      stk.push(i);
    }
  }

  return ret;
}
