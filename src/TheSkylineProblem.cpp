#include "TheSkylineProblem.hpp"

#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<pair<int, int>> TheSkylineProblem::getSkyline(vector<vector<int>>& buildings)
{
    vector<node> height;
    for (auto &b : buildings) {
        height.push_back(node(b[0], b[2], LEFT));
        height.push_back(node(b[1], b[2], RIGHT));
    }
    sort(height.begin(), height.end(), [](const node &a, const node &b) {
        if (a.x != b.x) return a.x < b.x;
        else if (a.type == LEFT && b.type == LEFT) return a.y > b.y;
        else if (a.type == RIGHT && b.type == RIGHT) return a.y < b.y;
        else return a.type == LEFT;
    });

    priority_queue<int> heap;
    unordered_map<int, int> mp;
    heap.push(0);
    vector<pair<int, int>> res;
    int pre = 0, cur = 0;
    for (auto &h : height) {
        if (h.type == LEFT) {
            heap.push(h.y);
        } else {
            ++mp[h.y];
            while (!heap.empty() && mp[heap.top()] > 0) {
                --mp[heap.top()];
                heap.pop();
            }
        }
        cur = heap.top();
        if (cur != pre) {
            res.push_back({h.x, cur});
            pre = cur;
        }
    }
    return res;
}
