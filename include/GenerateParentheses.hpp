#ifndef GENERTATE_PARENTHESES_HPP_
#define GENERTATE_PARENTHESES_HPP_

#include <vector>
#include <string>

using namespace std;

class GenerateParentheses {
public:
    vector<string> generateParenthesis(int n);

private:
    void helper(vector<string> &global, string &local, int left, int right);
};

#endif // GENERTATE_PARENTHESES_HPP_
