#include "FindTheDifference.hpp"

#include <vector>

using namespace std;

char FindTheDifference::findTheDifference(string s, string t) {
    vector<int> count(256, 0);

    for (auto c : t)
        count[c]++;

    for (auto c : s)
        count[c]--;

    char ret = ' ';
    for (int i = 0; i < 256; i++)
        if (count[i])
            ret = (char) i;

    return ret;
}