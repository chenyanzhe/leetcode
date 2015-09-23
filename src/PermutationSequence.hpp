#ifndef PERMUTATION_SEQUENCE_HPP_
#define PERMUTATION_SEQUENCE_HPP_

#include <string>
#include <vector>
using namespace std;

class PermutationSequence {
public:
	string getPermutation(int n, int k);
private:
	string getPermutation(vector<int>& numbers, int n, int k);
	int factorial(int n);
};

#endif // PERMUTATION_SEQUENCE_HPP_