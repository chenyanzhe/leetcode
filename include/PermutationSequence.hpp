#ifndef PERMUTATION_SEQUENCE_HPP_
#define PERMUTATION_SEQUENCE_HPP_

#include <string>
#include <vector>

using namespace std;

class PermutationSequence {
public:
    string getPermutation(int n, int k);

private:
    void
    backtrack(vector<int> &nums, int begin, vector<bool> &visited, int &k, vector<int> &local, vector<int> &global);
};

#endif // PERMUTATION_SEQUENCE_HPP_
