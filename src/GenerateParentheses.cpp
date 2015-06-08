#include "GenerateParentheses.hpp"

vector<string> GenerateParentheses::generateParenthesis(int n)
{
  if (n == 0) return ret;

  N = n * 2;
  field.resize(N, 0);
  nlbs = nrbs = 0;

  search(0);
  return ret;
}

void GenerateParentheses::search(int l)
{
  if (l == N) {
    string ans;
    for (auto f : field)
      ans.push_back((f == 1) ? '(' : ')');
    ret.push_back(ans);
    return;
  }

  field[l] = 1; nlbs++;
  if (isValidCandidate()) search(l + 1);
  nlbs--;

  field[l] = -1; nrbs++;
  if (isValidCandidate()) search(l + 1);
  nrbs--;
}

inline bool GenerateParentheses::isValidCandidate()
{
  return !(nlbs < nrbs || nlbs > N / 2 || nrbs > N / 2);
}
