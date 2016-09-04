#include "ImplementStrStr.hpp"

int ImplementStrStr::strStr(string haystack, string needle) {
    return strStr_RabinKarp(haystack, needle);
}

int ImplementStrStr::strStr_BruteForce(string &haystack, string &needle) {
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

int ImplementStrStr::strStr_RabinKarp(string &haystack, string &needle) {
    if (haystack.size() < needle.size()) return -1;

    long patHash; // pattern hash value
    int M = needle.size(); // pattern length
    long txtHash; // text(substr) hash value
    int N = haystack.size();
    long Q = (1L << 31) - 1; // a large prime
    int R = 256; // alphabet size
    long RM; // R^(M-1) % Q

    // calculate pattern hash
    patHash = 0;
    for (int j = 0; j < M; j++)
        patHash = (R * patHash + needle[j]) % Q;

    // calculate RM
    RM = 1;
    for (int j = 0; j < M - 1; j++)
        RM = (R * RM) % Q;

    // calculate initial text hash
    txtHash = 0;
    for (int j = 0; j < M; j++)
        txtHash = (R * txtHash + haystack[j]) % Q;

    if (patHash == txtHash) return 0;
    for (int i = M; i < N; i++) {
        txtHash = ((txtHash + Q - RM * haystack[i - M] % Q)) % Q;
        txtHash = (txtHash * R + haystack[i]) % Q;
        if (patHash == txtHash)
            return i - M + 1;
    }

    return -1;
}
