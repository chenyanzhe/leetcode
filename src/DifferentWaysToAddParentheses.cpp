#include "DifferentWaysToAddParentheses.hpp"

vector<int> DifferentWaysToAddParentheses::diffWaysToCompute(string input)
{
  vector<int> res;

  for (int i = 0; i < input.size(); i++) {
    char c = input[i];

    if (c == '+' || c == '-' || c == '*') {
      vector<int> a = diffWaysToCompute(input.substr(0, i));
      vector<int> b = diffWaysToCompute(input.substr(i + 1, input.size() - i - 1));

      for (auto _a : a) {
        for (auto _b : b) {
          if (c == '+')
            res.push_back(_a + _b);

          if (c == '-')
            res.push_back(_a - _b);

          if (c == '*')
            res.push_back(_a * _b);
        }
      }
    }
  }

  if (res.empty() && input.size())
    res.push_back(stoi(input));

  return res;
}