#ifndef PALINDROME_PARTITIONING_HPP_
#define PALINDROME_PARTITIONING_HPP_

#include <vector>
#include <string>

using namespace std;

class PalindromePartitioning {
public:
    vector<vector<string>> partition(string s);

private:
    void dfs(const string &s, vector<string> &path, vector<vector<string>> &result,
             int start);
};

#endif // PALINDROME_PARTITIONING_HPP_
