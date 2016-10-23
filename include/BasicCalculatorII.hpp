#ifndef BASIC_CALCULATOR_II_HPP_
#define BASIC_CALCULATOR_II_HPP_

#include <string>

using namespace std;

class BasicCalculatorII {
public:
    int calculate(string s);

private:
    int calc(int left, int right, char op);
};

#endif // BASIC_CALCULATOR_II_HPP_
