#include "WordLadderII.hpp"

#include <list>
#include <vector>
#include <utility>
using namespace std;

vector<vector<string>> WordLadderII::findLadders(string beginWord, string endWord, unordered_set<string> &wordList)
{
    unordered_set<string> current, next;
    unordered_set<string> visited { beginWord };
    unordered_map<string, vector<string>> father;
    vector<vector<string>> result;

    auto isTarget = [&](const string &s) { return s == endWord; };
    auto extendStates = [&](const string &word) {
        vector<string> result;

        for (int i = 0; i < word.size(); i++) {
            string new_word(word);
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == new_word[i]) continue;

                swap(c, new_word[i]);

                if ((new_word == endWord || wordList.count(new_word) > 0)
                    && !visited.count(new_word)) {
                    result.push_back(new_word);
                }

                swap(new_word[i], c);
            }
        }
        return result;
    };

    current.insert(beginWord);
    int depth = 0;
    bool found = false;

    while (!found && !current.empty()) {
        depth++;

        // mark `depth` nodes as visited
        for (const auto &word : current)
            visited.insert(word);

        for (const auto &word : current) {
            const auto &newStates = extendStates(word);
            for (const auto &state : newStates) {
                if (isTarget(state)) found = true;
                next.insert(state);
                father[state].push_back(word);
            }
        }
        current.clear();
        swap(current, next);
    }

    if (found) {
        vector<string> path;
        backtrace(father, path, beginWord, endWord, result);
    }

    return result;
}

void WordLadderII::backtrace(unordered_map<string, vector<string>> &father, vector<string> &path,
        const string &beginWord, const string &endWord, vector<vector<string>> &result)
{
    path.push_back(endWord);
    if (endWord == beginWord) {
        result.push_back(path);
        reverse(result.back().begin(), result.back().end());
    } else {
        for (const auto &p : father[endWord])
            backtrace(father, path, beginWord, p, result);
    }
    path.pop_back();
}
