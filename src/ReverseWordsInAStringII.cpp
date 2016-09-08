#include "ReverseWordsInAStringII.hpp"

void ReverseWordsInAStringII::reverseWords(string &s) {
    reverse(s, 0, s.size() - 1);
    int i = 0, j = 0;
    while (i < s.size()) {
        j = i;
        while (j < s.size() && s[j] != ' ')
            j++;
        reverse(s, i, j - 1);
        i = j + 1;
    }
}

void ReverseWordsInAStringII::reverse(string &s, int i, int j) {
    while (i < j)
        swap(s[i++], s[j--]);
}