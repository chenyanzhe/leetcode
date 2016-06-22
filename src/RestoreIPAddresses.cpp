#include "RestoreIPAddresses.hpp"

vector<string> RestoreIPAddresses::restoreIpAddresses(string s)
{
  // fast path
  if (s.size() < 4 || s.size() > 12)
    return res;

  bt(s, 0, 1, "");
  return res;
}

void RestoreIPAddresses::bt(string s, int i, int segment, string addr)
{
  if (i == s.size())
    return;

  if (segment == 4) {
    string seg = s.substr(i);

    if (valid(seg)) {
      res.push_back(addr + "." + seg);
      return;
    }
  }

  // segment can only be 1-3 digits
  for (int l = 1; l <= 3 && i + l < s.size(); l++) {
    string seg = s.substr(i, l);

    if (valid(seg))
      bt(s, i + l, segment + 1, (segment == 1) ? seg : addr + "." + seg);
  }
}

bool RestoreIPAddresses::valid(string segment)
{
  if (segment.size() == 0 || segment.size() > 3)
    return false;

  if (segment[0] == '0' && segment.size() > 1)
    return false;

  return stoi(segment) <= 255;
}
