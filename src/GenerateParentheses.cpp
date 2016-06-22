#include "GenerateParentheses.hpp"

vector<string> GenerateParentheses::generateParenthesis(int n)
{
  vector<string> ret;

  if (n == 0)
    return ret;

  helper(ret, "", n, n);
  return ret;
}

void GenerateParentheses::helper(vector<string>& ret, string paren, int left,
                                 int right)
{
  if (left == 0 && right == 0) {
    ret.push_back(paren);
    return;
  }

  if (left > 0)
    helper(ret, paren + "(", left - 1, right);

  if (left < right)
    helper(ret, paren + ")", left, right - 1);
}