#include "PerfectSquares.hpp"

#include <vector>
#include <queue>
using namespace std;

int PerfectSquares::numSquares(int n)
{
  queue<int>   q;
  vector<bool> visited(n + 1, false);
  int level = 0;
  // initialize the queue and visited vector
  int d = 1;

  while (d * d <= n) {
    if (d * d == n) {
      return level + 1;
    }

    q.push(n - d * d);
    visited[d * d] = true;
    d++;
  }

  level++;

  while (!q.empty()) {
    int sz = q.size();

    for (int i = 0; i < sz; i++) {
      int d = 1;
      int t = q.front();
      q.pop();

      while (d * d <= t) {
        if (d * d == t) {
          return level + 1;
        }

        if (!visited[n - t + d * d]) {
          q.push(t - d * d);
          visited[n - t + d * d] = true;
        }

        d++;
      }
    }

    level++;
  }

  return n;
}
