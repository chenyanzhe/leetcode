#ifndef JUMP_GAME_II_HPP_
#define JUMP_GAME_II_HPP_

#include <vector>
using namespace std;

class JumpGameII {
public:
  int jump(vector<int>& nums);
private:
  void jump(vector<int>& nums, int s, int lj, int& gj);
};

#endif // JUMP_GAME_II_HPP_
