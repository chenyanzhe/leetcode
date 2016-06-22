#include "SubstringWithConcatenationOfAllWords.hpp"

#include <unordered_map>
using namespace std;

vector<int> SubstringWithConcatenationOfAllWords::findSubstring(string s,
    vector<string>& words)
{
  vector<int> ret;
  int n = s.size();
  int cnt = words.size();

  if (n <= 0 || cnt <= 0)
    return ret;

  unordered_map<string, int> dict;

  for (int i = 0; i < cnt; i++)
    dict[words[i]]++;

  int wl = words[0].size();

  for (int i = 0; i < wl; i++) {
    unordered_map<string, int> wordCount;
    int count = 0;
    int left = i;

    for (int right = left; right + wl <= n; right += wl) {
      string w = s.substr(right, wl);

      if (dict.count(w)) { // valid word
        if (wordCount[w] < dict[w]) {
          // still have unused quorum
          wordCount[w]++;
          count++;
        } else {
          // quorum used up, moving the sliding window
          string dw;

          while ((dw = s.substr(left, wl)) != w) {
            wordCount[dw]--;
            count--;
            left += wl;
          }

          left += wl;
        }

        if (count == cnt) { // find all words
          ret.push_back(left);
          wordCount[s.substr(left, wl)]--;
          count--;
          left += wl;
        }
      } else {
        // invalid word
        wordCount.clear();
        count = 0;
        left = right + wl;
      }
    }
  }

  return ret;
}
