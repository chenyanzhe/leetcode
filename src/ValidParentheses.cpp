#include "ValidParentheses.hpp"

#include <stack>
using namespace std;

bool ValidParentheses::isValid(string s)
{
  stack<char> st;

  for (auto c : s) {
    if (c == '(' || c == '{' || c == '[')
      st.push(c);
    else {
      if (st.empty())
        return false;
      else if (c == ')' && st.top() != '(')
        return false;
      else if (c == '}' && st.top() != '{')
        return false;
      else if (c == ']' && st.top() != '[')
        return false;

      st.pop();
    }
  }

  return st.empty();
}