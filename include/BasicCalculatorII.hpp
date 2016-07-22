#ifndef BASIC_CALCULATOR_II_HPP_
#define BASIC_CALCULATOR_II_HPP_

#include <string>
#include <vector>

using namespace std;

class BasicCalculatorII {
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
};

#endif // BASIC_CALCULATOR_II_HPP_
