#include "WordLadderII.hpp"

#include <queue>

using namespace std;

vector<vector<string>> WordLadderII::findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
    vector<vector<string>> ret;
    if (wordList.empty()) return ret;

    bfs(wordList, beginWord, endWord, ret);

    return ret;
}

void
WordLadderII::bfs(unordered_set<string> &wordList, string beginWord, string endWord, vector<vector<string>> &path) {
    unordered_set<string> visited;
    unordered_map<string, vector<string>> father;

    auto neighbors = [&](const string &s) {
        vector<string> ret;

        for (int i = 0; i < s.size(); i++) {
            string new_word(s);

            for (char c = 'a'; c <= 'z'; c++) {
                if (c == new_word[i]) continue;

                swap(c, new_word[i]);
                if ((new_word == endWord || wordList.count(new_word)) && !visited.count(new_word)) {
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

    bool found = false;
    queue<string> q;
    q.push(beginWord);
    mark(beginWord);

    while (!q.empty()) {
        int nums = q.size();
        for (int c = 0; c < nums; c++) {
            string t = q.front();
            q.pop();
            for (auto nb : neighbors(t)) {
                mark(nb);
                father[nb].push_back(t);
                if (nb == endWord) {
                    found = true;
                }
                q.push(nb);
            }
        }
        if (found) {
            vector<string> route;
            genPath(father, path, beginWord, endWord, route);
            break;
        };
    }
}

void WordLadderII::genPath(unordered_map<string, vector<string>> &father, vector<vector<string>> &path,
                           string &beginWord, string &currWord, vector<string> &route) {
    route.push_back(currWord);
    if (currWord == beginWord) {
        path.push_back(route);
        reverse(path.back().begin(), path.back().end());
    } else {
        for (auto &curr : father[currWord])
            genPath(father, path, beginWord, curr, route);
    }
    route.pop_back();
}
