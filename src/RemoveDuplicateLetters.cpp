#include "RemoveDuplicateLetters.hpp"

#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

string RemoveDuplicateLetters::removeDuplicateLetters(string s)
{
  vector<int> freqs(256, 0);
  vector<bool> visited(256, false);
  stack<char> rec;
  string ret;

  for (auto c : s)
    freqs[c]++;

  for (auto c : s) {
    freqs[c]--;

    if (visited[c])
      continue;

    while (!rec.empty() && rec.top() > c && freqs[rec.top()]) {
      visited[rec.top()] = false;
      rec.pop();
    }

    rec.push(c);
    visited[c] = true;
  }

  while (!rec.empty()) {
    ret.append(1, rec.top());
    rec.pop();
  }

  reverse(ret.begin(), ret.end());
  return ret;
}
