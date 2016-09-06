#include "ReverseWordsInAString.hpp"

#include <utility>

using namespace std;

void ReverseWordsInAString::reverseWords(string &s) {
    // pre-processing
    bool inWord = false;
    int end = 0;
    int i = 0, j = 0;
    while (s[i] == ' ')
        i++;
    inWord = true;
    for (; i < s.size(); i++) {
        if (s[i] == ' ') {
            if (inWord) s[end++] = ' ';
            inWord = false;
        } else {
            s[end++] = s[i];
            inWord = true;
        }
    }
    if (end && s[end - 1] == ' ') end--;
    s.resize(end);

    // reverse the whole string
    i = 0;
    j = end - 1;
    while (i < j)
        swap(s[i++], s[j--]);

    // reverse every word
    i = 0;
    while (i < end) {
        j = i + 1;
        while (j < end && s[j] != ' ')
            j++;
        int a = i, b = j - 1;
        while (a < b)
            swap(s[a++], s[b--]);
        i = j + 1;
    }
}
