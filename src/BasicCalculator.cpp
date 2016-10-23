#include "BasicCalculator.hpp"

#include <stack>
#include <cctype>

using namespace std;

int BasicCalculator::calculate(string s) {
    stack<int> val;
    stack<char> op;

    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            int res = 0;
            while (i < s.size() && isdigit(s[i])) {
                res = res * 10 + s[i] - '0';
                i++;
            }
            val.push(res);
            i--;
        } else if (s[i] == '(') {
            op.push(s[i]);
        } else if (s[i] == '+' || s[i] == '-') {
            while (!op.empty() && op.top() != '(') {
                int r = val.top();
                val.pop();
                int l = val.top();
                val.pop();
                val.push(calc(l, r, op.top()));
                op.pop();
            }
            op.push(s[i]);
        } else if (s[i] == ')') {
            while (!op.empty() && op.top() != '(') {
                int r = val.top();
                val.pop();
                int l = val.top();
                val.pop();
                val.push(calc(l, r, op.top()));
                op.pop();
            }
            op.pop();
        }
    }

    while (!op.empty()) {
        int r = val.top();
        val.pop();
        int l = val.top();
        val.pop();
        val.push(calc(l, r, op.top()));
        op.pop();
    }

    return val.top();
}

int BasicCalculator::calc(int left, int right, char op) {
    return op == '+' ? left + right : left - right;
}
