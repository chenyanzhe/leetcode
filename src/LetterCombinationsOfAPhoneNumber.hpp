#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits);
private:
  static const vector<vector<char> > keyMap;
};
