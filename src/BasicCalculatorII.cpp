#include "BasicCalculatorII.hpp"

#include <stack>
using namespace std;

int BasicCalculatorII::calculate(string s)
{
    vector<BasicCalculatorII::Token> tks = parse(s);

    stack<int> vals;
    stack<BasicCalculatorII::Token> ops;
    vector<BasicCalculatorII::Token> postOrder;

    for (auto& t : tks) {
        if (t.type == BasicCalculatorII::Token::OPERAND)
            postOrder.push_back(t);
        else if (t.tk.op == '*' || t.tk.op == '/') {
            if (ops.empty() || ops.top().tk.op == '+' || ops.top().tk.op == '-')
                ops.push(t);
            else {
                while (!ops.empty() && (ops.top().tk.op == '*' || ops.top().tk.op == '/')) {
                    postOrder.push_back(ops.top());
                    ops.pop();
                }
                ops.push(t);
            }
        } else {
            while (!ops.empty()) {
                postOrder.push_back(ops.top());
                ops.pop();
            }
            ops.push(t);
        }
    }
    while (!ops.empty()) {
        postOrder.push_back(ops.top());
        ops.pop();
    }

    for (auto& t : postOrder) {
        if (t.type == BasicCalculatorII::Token::OPERAND)
            vals.push(t.tk.val);
        else {
            int second = vals.top(); vals.pop();
            int first = vals.top(); vals.pop();
            int result;
            switch(t.tk.op) {
            case '+':
                result = first + second;
                break;
            case '-':
                result = first - second;
                break;
            case '*':
                result = first * second;
                break;
            case '/':
                result = first / second;
                break;
            }
            vals.push(result);
        }
    }

    return vals.top();
}

vector<BasicCalculatorII::Token> BasicCalculatorII::parse(string s)
{
    vector<BasicCalculatorII::Token> res;
    int i = 0;
    int j = 0;
    while (i < s.size()) {
        BasicCalculatorII::Token t;
        j = i;
        if (s[j] == '+' || s[j] == '-' || s[j] == '*' || s[j] == '/') {
            t.type = BasicCalculatorII::Token::OPERATOR; t.tk.op = s[j];
            res.push_back(t);
            i++;
        } else if (s[j] == ' ') {
            i++;
        } else {
            do {
                j++;
            } while (j < s.size() && isdigit(s[j]));
            t.type = BasicCalculatorII::Token::OPERAND; t.tk.val = stoi(s.substr(i, j - i));
            res.push_back(t);
            i = j;
        }
    }
    return res;
}
