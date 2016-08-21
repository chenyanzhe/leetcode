#include "WordLadder.hpp"

#include <vector>
#include <queue>

using namespace std;

int WordLadder::ladderLength(string beginWord, string endWord, unordered_set<string> &wordList) {
    if (wordList.empty()) return 0;

    int ret = 0;
    bfs(wordList, beginWord, endWord, ret);

    return ret;
}

void WordLadder::bfs(unordered_set<string> &wordList, string beginWord, string endWord, int &dist) {
    unordered_set<string> visited;

    auto neighbors = [&](const string &s) {
        vector<string> ret;

        for (int i = 0; i < s.size(); i++) {
            string new_word(s);

            for (char c = 'a'; c <= 'z'; c++) {
                if (c == new_word[i]) continue;

                swap(c, new_word[i]);
                if ((new_word == endWord || wordList.count(new_word))
                    && !visited.count(new_word)) {
                    ret.push_back(new_word);
                }
                swap(new_word[i], c);
            }
        }

        return ret;
    };

    auto mark = [&](const string &s) {
        visited.insert(s);
    };

    queue<string> q;
    q.push(beginWord);
    mark(beginWord);
    int depth = 0;

    while (!q.empty()) {
        int nums = q.size();
        for (int c = 0; c < nums; c++) {
            string t = q.front();
            q.pop();
            for (auto nb : neighbors(t)) {
                mark(nb);
                if (nb == endWord) {
                    dist = depth + 2;
                    return;
                }
                q.push(nb);
            }
        }
        depth++;
    }
}