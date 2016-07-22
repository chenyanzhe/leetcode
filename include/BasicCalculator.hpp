#ifndef BASIC_CALCULATOR_HPP_
#define BASIC_CALCULATOR_HPP_

#include <string>
#include <vector>

using namespace std;

class BasicCalculator {
public:
    int calculate(string s);

private:
    typedef struct Token {
        enum {
            OPERATOR, OPERAND
        } type;
        union {
            char op;
            int val;
        } tk;
    } Token;

    vector<Token> parse(string s);

    int calc(int first, int second, char op);
};

#endif // BASIC_CALCULATOR_HPP_
