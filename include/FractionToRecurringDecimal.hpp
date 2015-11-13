#ifndef FRACTION_TO_RECURRING_DECIMAL_HPP_
#define FRACTION_TO_RECURRING_DECIMAL_HPP_

#include <string>
using namespace std;

class FractionToRecurringDecimal {
public:
    string fractionToDecimal(int numerator, int denominator);
private:
    string helper(long numerator, long denominator);
};

#endif // FRACTION_TO_RECURRING_DECIMAL_HPP_