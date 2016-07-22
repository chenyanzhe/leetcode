#ifndef REGULAR_EXPRESSION_MATCHING_HPP_
#define REGULAR_EXPRESSION_MATCHING_HPP_

#include <string>

using namespace std;

class RegularExpressionMatching {
public:
    bool isMatch(string s, string p);

private:
    bool isMatch(char _s, char _p);
};

#endif // REGULAR_EXPRESSION_MATCHING_HPP_
