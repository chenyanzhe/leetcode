#include "PalindromePartitioning.hpp"

vector<vector<string>> PalindromePartitioning::partition(string s)
{
  vector<string> path;
  vector<vector<string>> result;
  dfs(s, path, result, 0);
  return result;
}

void PalindromePartitioning::dfs(const string& s, vector<string>& path,
                                 vector<vector<string>>& result, int start)
{
  auto isPalindrome = [&](const string & s, int begin, int end) {
    while (begin < end && s[begin] == s[end]) {
      begin++;
      end--;
    }

    return begin >= end;
  };

  if (start == s.size()) {
    result.push_back(path);
    return;
  }

  for (int i = start; i < s.size(); i++) {
    if (isPalindrome(s, start, i)) {
      path.push_back(s.substr(start, i - start + 1));
      dfs(s, path, result, i + 1);
      path.pop_back();
    }
  }
}
