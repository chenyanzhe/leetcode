#include "Numberof1Bits.hpp"

int Numberof1Bits::hammingWeight(uint32_t n) {
    int ret = 0;
    while (n) {
        n &= (n - 1);
        ret++;
    }
    return ret;
}
