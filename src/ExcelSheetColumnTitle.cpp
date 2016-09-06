#include "ExcelSheetColumnTitle.hpp"

string ExcelSheetColumnTitle::convertToTitle(int n) {
    string ret;

    while (n) {
        char c = 'A' + (n - 1) % 26;
        ret = string(1, c) + ret;
        n = (n - 1) / 26;
    }

    return ret;
}
