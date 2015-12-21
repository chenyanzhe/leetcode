#include "MajorityElementII.hpp"

vector<int> MajorityElementII::majorityElement(vector<int>& nums)
{
    int cnt1 = 0, cnt2 = 0;
    int num1, num2;

    for (auto n : nums) {
        if (cnt1 == 0 || n == num1) {
            cnt1++;
            num1 = n;
        } else if (cnt2 == 0 || n == num2) {
            cnt2++;
            num2 = n;
        } else {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = cnt2 = 0;
    for (auto n : nums) {
        if (n == num1) cnt1++;
        else if (n == num2) cnt2++;
    }

    vector<int> result;
    if (cnt1 > nums.size() / 3) result.push_back(num1);
    if (cnt2 > nums.size() / 3) result.push_back(num2);
    return result;
}
