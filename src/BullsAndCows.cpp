#include "BullsAndCows.hpp"

#include <vector>

using namespace std;

string BullsAndCows::getHint(string secret, string guess) {
    int bulls = 0;
    int cows = 0;
    vector<int> cnts(10, 0);

    for (int i = 0; i < secret.size(); i++) {
        if (secret[i] == guess[i])
            bulls++;
        else {
            int s = secret[i] - '0';
            int g = guess[i] - '0';

            if (cnts[s] < 0) cows++;

            if (cnts[g] > 0) cows++;

            cnts[s]++;
            cnts[g]--;
        }
    }

    return to_string(bulls) + "A" + to_string(cows) + "B";
}