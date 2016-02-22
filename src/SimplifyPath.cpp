#include "SimplifyPath.hpp"

#include <sstream>
#include <vector>
using namespace std;

string SimplifyPath::simplifyPath(string path)
{
  string res, t;
  vector<string> stk;
  stringstream ss(path);
  
  while (getline(ss, t, '/')) {
    if (t == "" || t == ".") {
      continue;
    } else if (t == ".." && !stk.empty()) {
      stk.pop_back();
    } else if (t != "..") {
      stk.push_back(t);
    }
  }
  
  for (auto t : stk) {
    res += "/" + t;
  }

  return res.empty() ? "/" : res;
}
