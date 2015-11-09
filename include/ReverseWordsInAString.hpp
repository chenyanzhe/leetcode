#ifndef REVERSE_WORDS_IN_A_STRING_HPP_
#define REVERSE_WORDS_IN_A_STRING_HPP_

#include <string>
using namespace std;

class ReverseWordsInAString {
public:
    void reverseWords(string &s);
private:
    void standardize(string &s);
    void reverseString(string &s, int begin, int end);
};

#endif // REVERSE_WORDS_IN_A_STRING_HPP_