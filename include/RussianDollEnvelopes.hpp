#ifndef RUSSIAN_DOLL_ENVELOPES_HPP_
#define RUSSIAN_DOLL_ENVELOPES_HPP_

#include <vector>
#include <utility>

using namespace std;

class RussianDollEnvelopes {
public:
    int maxEnvelopes(vector<pair<int, int>> &envelopes);

private:
    int binarySearch(vector<int> &tails, int end, int target);
};

#endif // RUSSIAN_DOLL_ENVELOPES_HPP_