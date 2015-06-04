#include <string>
using namespace std;

class Solution {
public:
  string intToRoman(int num);
private:
  string digitToRoman(int digit, int level);
};
