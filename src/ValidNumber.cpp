#include "ValidNumber.hpp"

// [+-]?(([0-9]*.?[0-9]+)|([0-9]+.?[0-9]*))([eE][+-]?[0-9]+)?
bool ValidNumber::isNumber(string s) {
    if (!stripSpaces(s)) return false;
    int d = -1, e = -1;
    if (!find(s, d, e)) return false;
    if (e != -1) {
        int j = e + 1;
        if (j >= s.size()) return false;
        if (s[j] == '+' || s[j] == '-') j++;
        if (j >= s.size()) return false;
        while (j < s.size()) {
            if (s[j] < '0' || s[j] > '9') return false;
            j++;
        }
    }
    if (e == 0) return false;
    int i = 0;
    if (s[i] == '+' || s[i] == '-') i++;
    if (e == -1) e = s.size();
    if (d != -1) {
        if (i == d && d == e - 1) return false;
        while (i < d) {
            if (s[i] < '0' || s[i] > '9') return false;
            i++;
        }
        i = d + 1;
        while (i < e) {
            if (s[i] < '0' || s[i] > '9') return false;
            i++;
        }
    } else {
        if (i == e) return false;
        while (i < e) {
            if (s[i] < '0' || s[i] > '9') return false;
            i++;
        }
    }
    return true;
}

bool ValidNumber::stripSpaces(string &s) {
    if (s.empty()) return false;
    int i = 0, j = s.size() - 1;
    while (i < s.size() && s[i] == ' ')
        i++;
    while (j >= 0 && s[j] == ' ')
        j--;
    if (i > j) return false;
    s = s.substr(i, j-i+1);
    return true;
}

bool ValidNumber::find(string s, int &d, int &e) {
    bool dFlag = false;
    bool eFlag = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') {
            if (dFlag) return false;
            dFlag = true;
            d = i;
        }
        if (s[i] == 'e' || s[i] == 'E') {
            if (eFlag) return false;
            eFlag = true;
            e = i;
        }
    }
    if (d != -1 && e != -1 && d > e) return false;
    return true;
}