#include "BasicCalculatorII.hpp"

#include <stack>

using namespace std;

int BasicCalculatorII::calculate(string s) {
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
        } else if (s[i] == '*' || s[i] == '/') {
            while (!op.empty() && (op.top() == '*' || op.top() == '/')) {
                int r = val.top();
                val.pop();
                int l = val.top();
                val.pop();
                val.push(calc(l, r, op.top()));
                op.pop();
            }
            op.push(s[i]);
        } else if (s[i] == '+' || s[i] == '-') {
            while (!op.empty()) {
                int r = val.top();
                val.pop();
                int l = val.top();
                val.pop();
                val.push(calc(l, r, op.top()));
                op.pop();
            }
            op.push(s[i]);
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

int BasicCalculatorII::calc(int left, int right, char op) {
    switch (op) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
        default:
            return 0;
    }
}
