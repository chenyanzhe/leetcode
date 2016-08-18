#ifndef VALID_NUMBER_HPP_
#define VALID_NUMBER_HPP_

#include <string>

using namespace std;

class ValidNumber {
public:
    bool isNumber(string s);

private:
    bool isNumber_Normal(string s);

    bool isNumber_StateMachine(const char *s);
};

#endif // VALID_NUMBER_HPP_
