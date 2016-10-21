#ifndef PALINDROME_PAIRS_HPP_
#define PALINDROME_PAIRS_HPP_

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class PalindromePairs {
public:
    vector<vector<int>> palindromePairs(vector<string> &words);

private:
    bool isPalindrome(string str);
};

#endif // PALINDROME_PAIRS_HPP_