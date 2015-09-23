#include "PermutationSequence.hpp"

string PermutationSequence::getPermutation(int n, int k)
{
	vector<int> numbers;
	for (int i = 1; i <= n; i++)
		numbers.push_back(i);

	return getPermutation(numbers, n, k - 1);
}

string PermutationSequence::getPermutation(vector<int>& numbers, int n, int k)
{
	if (n <= 0) return "";
	if (n == 1) return to_string(numbers[0]);

	int divider = factorial(n - 1);
	int groups = k / divider;
	int remaining = k % divider;
	string heading = to_string(numbers[groups]);
	for (int i = groups; i < n - 1; i++)
		numbers[i] = numbers[i+1];
	return heading + getPermutation(numbers, n - 1, remaining);
}

int PermutationSequence::factorial(int n)
{
	int ret = 1;
	for (int i = 1; i <= n; i++)
		ret *= i;
	return ret;
}