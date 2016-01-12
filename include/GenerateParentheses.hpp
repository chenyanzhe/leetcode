#ifndef GENERTATE_PARENTHESES_HPP_
#define GENERTATE_PARENTHESES_HPP_

#include <vector>
#include <string>
using namespace std;

class GenerateParentheses
{
public:
  vector<string> generateParenthesis(int n);

private:
  void search(int l);
  bool isValidCandidate();

private:
  int N;
  vector<string> ret;
  vector<int> field;
  int nlbs;
  int nrbs;
};

#endif // GENERTATE_PARENTHESES_HPP_
