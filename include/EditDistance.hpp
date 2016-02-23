#ifndef EDIT_DISTANCE_HPP_
#define EDIT_DISTANCE_HPP_

#include <string>
using namespace std;

class EditDistance
{
public:
  int minDistance(string word1, string word2);
private:
  int minDistance_Raw(string word1, string word2);
  int minDistance_Optimized(string word1, string word2);
};

#endif // EDIT_DISTANCE_HPP_
