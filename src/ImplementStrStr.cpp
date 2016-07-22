#include "ImplementStrStr.hpp"

int ImplementStrStr::strStr(string haystack, string needle) {
    int hlen = haystack.size();
    int nlen = needle.size();

    for (int i = 0; i < hlen - nlen + 1; i++) {
        int j;
        int k;

        for (j = i, k = 0; k < nlen; j++, k++) {
            if (haystack[j] != needle[k])
                break;
        }

        if (k == nlen)
            return i;
    }

    return -1;
}
