#include "Numberof1Bits.hpp"

int Numberof1Bits::hammingWeight(uint32_t n) {
    int result = 0;

    while (n != 0) {
        result += n & 1;
        n >>= 1;
    }

    return result;
}
