#include "SubsetsII.hpp"

using namespace std;

vector<vector<int>> SubsetsII::subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<int> node;
    dfs(nums, 0, node);
    return res;
}

void SubsetsII::dfs(vector<int> &nums, int i, vector<int> &node) {
    if (i == nums.size()) {
        res.push_back(node);
        return;
    }

    int j = i - 1;

    while (j >= 0 && nums[j] == nums[i])
        j--;

    int d = i - (j + 1);

    if (d == 0 ||
        (node.size() >= d && node[node.size() - d] == nums[i])) {
        // choose nums[i]
        node.push_back(nums[i]);
        dfs(nums, i + 1, node);
        node.pop_back();
    }

    // don't choose nums[i]
    dfs(nums, i + 1, node);
}
