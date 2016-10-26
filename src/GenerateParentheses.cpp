#include "GenerateParentheses.hpp"

vector<string> GenerateParentheses::generateParenthesis(int n) {
    vector<string> ret;
    string cur;
    helper(ret, cur, n, n);
    return ret;
}

void GenerateParentheses::helper(vector<string> &global, string &local, int left, int right) {
    if (left == 0 && right == 0) {
        global.push_back(local);
        return;
    }

    if (right > left) {
        local.push_back(')');
        helper(global, local, left, right - 1);
        local.pop_back();
    }

    if (left > 0) {
        local.push_back('(');
        helper(global, local, left - 1, right);
        local.pop_back();
    }
}