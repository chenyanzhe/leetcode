#include "GenerateParentheses.hpp"
#include <stack>

vector<string> GenerateParentheses::generateParenthesis(int n)
{
  if (n == 0) return ret;
  N = n * 2;
  field.resize(N, 0);

  search(0);
  return ret;
}

void GenerateParentheses::search(int l)
{
  if (l == N) {
    string ans;
    for (auto f : field)
      ans.push_back((f == 1) ? '(' : ')');
    if (isValidParenthesis(ans)) ret.push_back(ans);
    return;
  }

  field[l] = 1;
  if (passSanityCheck(l)) search(l + 1);

  field[l] = -1;
  if (passSanityCheck(l)) search(l + 1);
}

bool GenerateParentheses::isValidParenthesis(string s)
{
  stack<char> stk;

  for (auto c : s) {
    if (!stk.empty() && stk.top() == '(' && c == ')')
      stk.pop();
    else
      stk.push(c);
  }

  return stk.empty();
}

bool GenerateParentheses::passSanityCheck(int l)
{
  int lbs = 0;
  int rbs = 0;
  int div = 0;

  for (size_t i = 0; i <= l; i++) {
    if (field[i] == 1) lbs++;
    else if (field[i] == -1) rbs++;
    div += field[i];
    if (div < 0) return false;
  }

  if (lbs > N || rbs > N) return false;
  return true;
}
