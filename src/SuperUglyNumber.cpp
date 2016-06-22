#include "SuperUglyNumber.hpp"

#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int SuperUglyNumber::nthSuperUglyNumber(int n, vector<int>& primes)
{
  if (n == 1)
    return 1;

  int k = primes.size();
  typedef pair<int, int> prime_t; // prime val with its source
  struct OrderByVal {
    bool operator() (prime_t& a, prime_t& b)
    {
      return a.first > b.first;
    }
  };
  typedef priority_queue<prime_t, vector<prime_t>, OrderByVal> primes_q;
  vector<queue<int>> candidates(k);
  primes_q q;
  int val, src;

  for (int i = 0; i < k; i++) {
    q.push(make_pair(primes[i], i));
    candidates[i].push(primes[i]);
  }

  while (n > 1) {
    val = q.top().first;
    src = q.top().second;

    for (int i = src; i < k; i++)
      candidates[i].push(val * primes[i]);

    candidates[src].pop();
    q.pop();
    q.push(make_pair(candidates[src].front(), src));
    n--;
  }

  return val;
}
