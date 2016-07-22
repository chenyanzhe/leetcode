#include "ExcelSheetColumnTitle.hpp"

string ExcelSheetColumnTitle::convertToTitle(int n) {
    string result;

    while (n > 0) {
        char bit = 'A' + (n - 1) % 26;
        result = string(1, bit) + result;
        n = (n - 1) / 26;
    }

    return result;
}
