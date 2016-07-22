#include "StringToInteger.hpp"

#include <climits>

using namespace std;

int StringToInteger::myAtoi(string str) {
    int sign = 1;
    int base = 0;
    int i = 0;

    // discard all leading whitespaces
    while (str[i] == ' ')
        i++;

    // get the sign of the number
    if (str[i] == '+' || str[i] == '-')
        sign = 1 - 2 * (str[i++] == '-');

    // ignore invalid input
    while (str[i] >= '0' && str[i] <= '9') {
        // detect overflow or underflow
        if (base > INT_MAX / 10 || (base == INT_MAX / 10 &&
                                    str[i] - '0' > INT_MAX % 10)) {
            if (sign == 1)
                return INT_MAX;
            else
                return INT_MIN;
        }

        base = base * 10 + (str[i++] - '0');
    }

    return base * sign;
}
