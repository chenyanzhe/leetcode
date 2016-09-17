#include "PermutationSequence.hpp"

string PermutationSequence::getPermutation(int n, int k) {
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        nums[i] = i + 1;
    vector<int> global;
    vector<int> local;
    vector<bool> visited(n, false);
    backtrack(nums, 0, visited, k, local, global);

    string ret = "";
    for (int i = 0; i < n; i++)
        ret += to_string(global[i]);
    return ret;
}

void PermutationSequence::backtrack(vector<int> &nums, int begin, vector<bool> &visited, int &k, vector<int> &local,
                                    vector<int> &global) {
    if (k == 0) return;
    if (begin == nums.size()) {
        k--;
        global = local;
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            local.push_back(nums[i]);
            backtrack(nums, begin + 1, visited, k, local, global);
            local.pop_back();
            visited[i] = false;
        }
    }
}
