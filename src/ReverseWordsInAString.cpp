#include "ReverseWordsInAString.hpp"

#include <cctype>
#include <algorithm>
#include <iostream>
using namespace std;

void ReverseWordsInAString::reverseWords(string &s)
{
    standardize(s);
    reverseString(s, 0, s.size() - 1);
    cout << s << endl;
    int i = 0;
    int j = 0;
    for (; j < s.size(); j++) {
        if (!isspace(s[j]))
            continue;
        reverseString(s, i, j - 1);
        i = j + 1;
    }
    // reverse the last word
    if (j - 1 > i)
        reverseString(s, i, j - 1);
}

void ReverseWordsInAString::standardize(string &s)
{
    // 1. remove leading and trailing spaces
    // 2. reduce to single space between words
    int i = 0;
    int j = 0;
    bool inWord = false;
    for (; i < s.size(); i++) {
        if (!isspace(s[i])) {
            inWord = true;
            s[j++] = s[i];
        } else {
            if (inWord) {
                s[j++] = ' ';
                inWord = false;
            }
        }
    }
    if (j > 0 && isspace(s[j-1]))
        j--;
    s = s.substr(0, j);
}

void ReverseWordsInAString::reverseString(string &s, int begin, int end)
{
    while (begin < end) {
        swap(s[begin], s[end]);
        begin++;
        end--;
    }
}