#include "RemoveInvalidParentheses.hpp"

vector<string> RemoveInvalidParentheses::removeInvalidParentheses(string s)
{
  int rmL = 0;
  int rmR = 0;

  for (auto c : s) {
    if(c == '(') {
      rmL++;
    }

    if(c == ')') {
      if(rmL != 0) {
        rmL--;
      } else {
        rmR++;
      }
    }
  }

  set<string> result;
  string current = "";
  dfs(result, 0, s, rmL, rmR, 0, current);
  vector<string> ret;

  for (auto r : result) {
    ret.push_back(r);
  }

  return ret;
}

void RemoveInvalidParentheses::dfs(set<string>& result, int i, const string& s,
                                   int rmL, int rmR, int open, string current)
{
  if (i == s.size() && rmL == 0 && rmR == 0 && open == 0) {
    result.insert(current);
    return;
  }

  if (i == s.size() || rmL < 0 || rmR < 0 || open < 0) {
    return;
  }

  char c = s[i];

  if (c == '(') {
    dfs(result, i + 1, s, rmL - 1, rmR, open, current);
    dfs(result, i + 1, s, rmL, rmR, open + 1, current + "(");
  } else if (c == ')') {
    dfs(result, i + 1, s, rmL, rmR - 1, open, current);
    dfs(result, i + 1, s, rmL, rmR, open - 1, current + ")");
  } else {
    dfs(result, i + 1, s, rmL, rmR, open, current + string(1, c));
  }
}