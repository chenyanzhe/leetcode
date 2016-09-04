#ifndef IMPLEMENT_STRSTR_HPP_
#define IMPLEMENT_STRSTR_HPP_

#include <string>

using namespace std;

class ImplementStrStr {
public:
    int strStr(string haystack, string needle);

private:
    int strStr_BruteForce(string &haystack, string &needle);

    int strStr_RabinKarp(string &haystack, string &needle);
};

#endif // IMPLEMENT_STRSTR_HPP_
