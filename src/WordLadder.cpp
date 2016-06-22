#include "WordLadder.hpp"

#include <queue>
#include <vector>
#include <utility>
using namespace std;

int WordLadder::ladderLength(string beginWord, string endWord,
                             unordered_set<string>& wordList)
{
  queue<string> q;
  unordered_set<string> visited;
  auto isTarget = [&](const string & s) {
    return s == endWord;
  };
  auto extendStates = [&](const string & word) {
    vector<string> result;

    for (int i = 0; i < word.size(); i++) {
      string new_word(word);

      for (char c = 'a'; c <= 'z'; c++) {
        if (c == new_word[i])
          continue;

        swap(c, new_word[i]);

        if ((new_word == endWord || wordList.count(new_word) > 0)
            && !visited.count(new_word)) {
          result.push_back(new_word);
          visited.insert(new_word);
        }

        swap(new_word[i], c);
      }
    }

    return result;
  };
  q.push(beginWord);
  int depth = 0;

  while (!q.empty()) {
    depth++;
    int k = q.size(); // number of nodes in `depth` level

    for (int i = 0; i < k; i++) {
      string front = q.front();
      q.pop();
      const auto& newStates = extendStates(front);

      for (const auto& state : newStates) {
        if (isTarget(state))
          return depth + 1;

        q.push(state);
      }
    }
  }

  return 0;
}
