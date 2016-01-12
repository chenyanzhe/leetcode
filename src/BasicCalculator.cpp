#include "BasicCalculator.hpp"

#include <cctype>
#include <stack>
using namespace std;

int BasicCalculator::calculate(string s)
{
  vector<BasicCalculator::Token> tks = parse(s);
  stack<char> ops;
  stack<int> vals;

  for (auto& t : tks) {
    if (t.type == BasicCalculator::Token::OPERAND) {
      vals.push(t.tk.val);
    } else if (t.tk.op == ')') {
      if (ops.top() != '(') {
        int second = vals.top();
        vals.pop();
        int first = vals.top();
        vals.pop();
        vals.push(calc(first, second, ops.top()));
        ops.pop();
      }

      ops.pop();
    } else if (t.tk.op == '(') {
      ops.push(t.tk.op);
    } else {
      if (!ops.empty() && (ops.top() == '+' || ops.top() == '-')) {
        int second = vals.top();
        vals.pop();
        int first = vals.top();
        vals.pop();
        vals.push(calc(first, second, ops.top()));
        ops.pop();
      }

      ops.push(t.tk.op);
    }
  }

  if (!ops.empty()) {
    int second = vals.top();
    vals.pop();
    int first = vals.top();
    vals.pop();
    vals.push(calc(first, second, ops.top()));
    ops.pop();
  }

  return vals.top();
}

vector<BasicCalculator::Token> BasicCalculator::parse(string s)
{
  vector<BasicCalculator::Token> res;
  int i = 0;
  int j = 0;

  while (i < s.size()) {
    BasicCalculator::Token t;
    j = i;

    if (s[j] == '(' || s[j] == ')' || s[j] == '+' || s[j] == '-') {
      t.type = BasicCalculator::Token::OPERATOR;
      t.tk.op = s[j];
      res.push_back(t);
      i++;
    } else if (s[j] == ' ') {
      i++;
    } else {
      do {
        j++;
      } while (j < s.size() && isdigit(s[j]));

      t.type = BasicCalculator::Token::OPERAND;
      t.tk.val = stoi(s.substr(i, j - i));
      res.push_back(t);
      i = j;
    }
  }

  return res;
}

int BasicCalculator::calc(int first, int second, char op)
{
  if (op == '+') {
    return first + second;
  } else {
    return first - second;
  }
}
