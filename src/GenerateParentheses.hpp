#ifndef GENERTATE_PARENTHESES_HPP_
#define GENERTATE_PARENTHESES_HPP_

#include <vector>
#include <string>
using namespace std;

class GenerateParentheses {
public:
  vector<string> generateParenthesis(int n);
private:
  int N;
  vector<string> ret;
  vector<int> field;

  void search(int l);
  bool passSanityCheck(int l);
  bool isValidParenthesis (string str);
};

#endif // GENERTATE_PARENTHESES_HPP_
