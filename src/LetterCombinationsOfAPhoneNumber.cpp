#include "LetterCombinationsOfAPhoneNumber.hpp"

#include <queue>

using namespace std;

vector<string> LetterCombinationsOfAPhoneNumber::letterCombinations(
        string digits) {
    vector<string> mapping{"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    queue<string> q;
    q.push("");

    for (int i = 0; i < digits.size(); i++) {
        while (q.front().size() == i) {
            string t = q.front();
            q.pop();

            for (auto c : mapping[digits[i] - '0'])
                q.push(t + string(1, c));
        }
    }

    vector<string> res;

    if (digits.size() == 0)
        return res;

    while (!q.empty()) {
        res.push_back(q.front());
        q.pop();
    }

    return res;
}
