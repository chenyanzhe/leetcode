#include "ValidParentheses.hpp"

#include <stack>
using namespace std;

bool Solution::isValid(string s)
{
  stack<char> stk;

  for (auto c : s) {
    if (!stk.empty() && isPair(stk.top(), c))
      stk.pop();
    else
      stk.push(c);
  }

  return stk.empty();
}

bool Solution::isPair(char a, char b)
{
  if (a == '(' && b == ')') return true;
  if (a == '{' && b == '}') return true;
  if (a == '[' && b == ']') return true;
  return false;
}
