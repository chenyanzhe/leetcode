#include "CountPrimes.hpp"

#include <cmath>
#include <vector>

using namespace std;

int CountPrimes::countPrimes(int n) {
    vector<bool> prime(n, true);
    prime[0] = false, prime[1] = false;
    for (int i = 0; i < sqrt(n); i++) {
        if (prime[i]) {
            for (int j = i * i; j < n; j += i) {
                prime[j] = false;
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < prime.size(); i++)
        if (prime[i]) ret++;
    return ret;
}
