#include "AddDigits.hpp"

int AddDigits::addDigits(int num) {
    while (num >= 10) {
        int acc = 0;

        while (num > 0) {
            acc += num % 10;
            num /= 10;
        }

        num = acc;
    }

    return num;
}