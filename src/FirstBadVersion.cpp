#include "FirstBadVersion.hpp"

#include <cstdint>
using namespace std;

FirstBadVersion::FirstBadVersion(VersionChecker checker)
  : isBadVersion(checker)
{
}

int FirstBadVersion::firstBadVersion(int n)
{
  uint64_t l = static_cast<uint64_t>(1);
  uint64_t r = static_cast<uint64_t>(n);

  while (l <= r) {
    if (l == r) {
      return l;
    }

    uint64_t m = (l + r) / 2;

    if (isBadVersion(m)) {
      if ((m == l) || !isBadVersion(m - 1)) {
        return m;
      } else {
        r = m - 1;
      }
    } else {
      l = m + 1;
    }
  }

  return 0;
}
