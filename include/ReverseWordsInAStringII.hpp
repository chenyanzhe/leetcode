#ifndef REVERSE_WORDS_IN_A_STRING_II_HPP_
#define REVERSE_WORDS_IN_A_STRING_II_HPP_

#include <string>

using namespace std;

class ReverseWordsInAStringII {
public:
    void reverseWords(string &s);

private:
    void reverse(string &s, int i, int j);
};

#endif // REVERSE_WORDS_IN_A_STRING_II_HPP_