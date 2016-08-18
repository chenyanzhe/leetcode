#include "ValidNumber.hpp"

bool ValidNumber::isNumber(string s) {
    auto first = s.find_first_not_of(' ');
    if (first == string::npos) return false;

    auto last = s.find_last_not_of(' ');
    if (last == string::npos) return false;

    s = s.substr(first, (last - first + 1));

    if (s.empty()) return false;
    return isNumber_StateMachine(s.c_str());
}

bool ValidNumber::isNumber_Normal(string s) {
    int i = 0;

    // skip the white spaces
    for (; s[i] == ' '; i++) {}

    // check the significand
    if (s[i] == '+' || s[i] == '-') {
        i++;  // skip the sign if exist
    }

    int n_nm, n_pt;

    for (n_nm = 0, n_pt = 0; (s[i] <= '9' && s[i] >= '0') || s[i] == '.'; i++)
        s[i] == '.' ? n_pt++ : n_nm++;

    if (n_pt > 1 || n_nm < 1)   // no more than one point, at least one digit
        return false;

    // check the exponent if exist
    if (s[i] == 'e') {
        i++;

        if (s[i] == '+' || s[i] == '-') {
            i++;  // skip the sign
        }

        int n_nm = 0;

        for (; s[i] >= '0' && s[i] <= '9'; i++, n_nm++) {}

        if (n_nm < 1)
            return false;
    }

    // skip the trailing white spaces
    for (; s[i] == ' '; i++) {}

    return s[i] == 0; // must reach the ending 0 of the string
}

bool ValidNumber::isNumber_StateMachine(const char *s) {
    enum InputType {
        INVALID, SIGN, DOT, E, DIGIT, LEN
    };
    int trans[][LEN] = {
            {-1, 1,  3,  -1, 2},
            {-1, -1, 3,  -1, 2},
            {-1, -1, 4,  5,  2},
            {-1, -1, -1, -1, 4},
            {-1, -1, -1, 5,  4},
            {-1, 6,  -1, -1, 7},
            {-1, -1, -1, -1, 7},
            {-1, -1, -1, -1, 7}
    };
    int state = 0;
    while (*s) {
        InputType input;
        if (*s == '+' || *s == '-') {
            input = SIGN;
        } else if (*s == '.') {
            input = DOT;
        } else if (*s == 'e' || *s == 'E') {
            input = E;
        } else if (isdigit(*s)) {
            input = DIGIT;
        } else {
            input = INVALID;
        }
        state = trans[state][input];
        if (state == -1) return false;
        s++;
    }
    return state == 2 || state == 4 || state == 7;
}