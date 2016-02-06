#ifndef WILDCARD_MATCHING_HPP_
#define WILDCARD_MATCHING_HPP_

#include <string>
using namespace std;

class WildcardMatching
{
public:
  bool isMatch(string s, string p);
private:
  bool isMatch_DynamicProgramming(string s, string p);
  bool isMatch_Greedy(string s, string p);
};

#endif // WILDCARD_MATCHING_HPP_
