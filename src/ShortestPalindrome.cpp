#include "ShortestPalindrome.hpp"

#include <algorithm>
#include <vector>
using namespace std;

string ShortestPalindrome::shortestPalindrome(string s)
{
  if (s.size() <= 1)
    return s;

  string reverse_str = s;
  reverse(reverse_str.begin(), reverse_str.end());
  string new_str = s + "#" + reverse_str;
  vector<int> position(new_str.size(), 0);

  for (int i = 1; i < position.size(); i++) {
    int pre_pos = position[i - 1];

    while (pre_pos > 0 && new_str[pre_pos] != new_str[i])
      pre_pos = position[pre_pos - 1];

    position[i] = pre_pos + ((new_str[pre_pos] == new_str[i]) ? 1 : 0);
  }

  string tail = s.substr(position[position.size() - 1]);
  reverse(tail.begin(), tail.end());
  return tail + s;
}
