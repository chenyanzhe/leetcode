#include "JumpGameII.hpp"

using namespace std;

int JumpGameII::jump(vector<int> &nums) {
    if (nums.size() == 1)
        return 0;

    int next = 0;
    int steps = 1;
    int begin = 0;
    int end = nums[0];

    while (end < nums.size() - 1) {
        steps++;

        for (int i = begin; i <= end; i++)
            next = max(next, i + nums[i]);

        begin = end + 1;
        end = next;
    }

    return steps;
}
