#ifndef VALID_NUMBER_HPP_
#define VALID_NUMBER_HPP_

#include <string>
using namespace std;

class ValidNumber {
public:
    bool isNumber(string s);
private:
    bool stripSpaces(string &s);
    bool find(string s, int &d, int &e);
};

#endif // VALID_NUMBER_HPP_