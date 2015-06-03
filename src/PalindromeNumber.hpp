class Solution {
public:
  bool isPalindrome(int x);
private:
  // Get integer x's ith digit, start from the lowest digit
  //   e.g. given x = 321, getDigit(x, 1) = 1, getDigit(x, 3) = 3
  // Suppose both x and i are positive
  // When i exceeds MAX_INT's digits number, return 0
  //   e.g. getDigit(x, 11) = 0 when int is 32-bit
  int getDigit(int x, int i);
};
