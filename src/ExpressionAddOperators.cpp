#include "ExpressionAddOperators.hpp"

vector<string> ExpressionAddOperators::addOperators(string num, int target) {
    vector<string> res;
    dfs(num, target, "", 0, 0, res);
    return res;
}

void ExpressionAddOperators::dfs(string num, int target, string expr,
                                 long currRes, long prevNum, vector<string> &res) {
    if ((currRes == target) && (num.size() == 0)) {
        res.push_back(expr);
        return;
    }

    for (int i = 1; i <= num.size(); i++) {
        string currStr = num.substr(0, i);

        if ((currStr.size() > 1) && (currStr[0] == '0')) {
            // invalid number
            return;
        }

        long currNum = stol(currStr);
        string next = num.substr(i);

        if (expr.size() != 0) {
            // *
            dfs(next, target, expr + "*" + currStr,
                (currRes - prevNum) + prevNum * currNum, prevNum * currNum, res);
            // +
            dfs(next, target, expr + "+" + currStr, currRes + currNum, currNum, res);
            // -
            dfs(next, target, expr + "-" + currStr, currRes - currNum, -currNum, res);
        } else
            dfs(next, target, currStr, currNum, currNum, res);
    }
}
