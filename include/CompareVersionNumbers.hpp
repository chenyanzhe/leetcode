#ifndef COMPARE_VERSION_NUMBERS_HPP_
#define COMPARE_VERSION_NUMBERS_HPP_

#include <string>
#include <vector>

using namespace std;

class CompareVersionNumbers {
public:
    int compareVersion(string version1, string version2);

private:
    int compareDigitsString(string num1, string num2);

    void tokenize(const string &version, vector<string> &versions);
};

#endif // COMPARE_VERSION_NUMBERS_HPP_
