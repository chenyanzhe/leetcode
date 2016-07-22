#ifndef LONGEST_PALINDROMIC_SUBSTRING_HPP_
#define LONGEST_PALINDROMIC_SUBSTRING_HPP_

#include <string>

using namespace std;

class LongestPalindromicSubstring {
public:
    string longestPalindrome(string s);

private:
    string expandAroundCenter(string s, int c1, int c2);
};

#endif // LONGEST_PALINDROMIC_SUBSTRING_HPP_
