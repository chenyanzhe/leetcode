#ifndef ISOMORPHIC_STRINGS_HPP_
#define ISOMORPHIC_STRINGS_HPP_

#include <string>
using namespace std;

class IsomorphicStrings
{
public:
  bool isIsomorphic(string s, string t);
private:
  void remap(string& s);
};

#endif // ISOMORPHIC_STRINGS_HPP_
