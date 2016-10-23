#ifndef BASIC_CALCULATOR_HPP_
#define BASIC_CALCULATOR_HPP_

#include <string>

using namespace std;

class BasicCalculator {
public:
    int calculate(string s);

private:
    int calc(int left, int right, char op);
};

#endif // BASIC_CALCULATOR_HPP_
