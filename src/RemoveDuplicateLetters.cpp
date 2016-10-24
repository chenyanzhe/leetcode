#include "RemoveDuplicateLetters.hpp"

#include <vector>

using namespace std;

string RemoveDuplicateLetters::removeDuplicateLetters(string s) {
    vector<int> freq(256, 0);
    vector<bool> visited(256, false);
    string ret;

    for (auto c : s) freq[c]++;

    for (auto c : s) {
        freq[c]--;

        if (visited[c]) continue;

        while (!ret.empty() && ret.back() > c && freq[ret.back()]) {
            visited[ret.back()] = false;
            ret.pop_back();
        }

        ret += c;
        visited[c] = true;
    }

    return ret;
}
