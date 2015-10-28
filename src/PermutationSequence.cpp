#include "PermutationSequence.hpp"

string PermutationSequence::getPermutation(int n, int k)
{
    string s(n, '0');
    for (int i = 0; i < n; i++)
        s[i] += i + 1;
    return kth_permutation(s, k);
}

string PermutationSequence::kth_permutation(string seq, int k)
{
    int n = seq.size();
    string S = seq;
    string result;

    int base = factorial(n - 1);
    --k;

    for (int i = n - 1; i > 0; k %= base, base /= i, i--) {
        auto a = S.begin() + k / base;
        result.push_back(*a);
        S.erase(a);
    }

    result.push_back(S[0]);
    return result;
}

int PermutationSequence::factorial(int n)
{
    int ret = 1;
    for (int i = 1; i <= n; i++)
        ret *= i;
    return ret;
}