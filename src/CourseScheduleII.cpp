#include "CourseScheduleII.hpp"

#include <algorithm>

using namespace std;

vector<int> CourseScheduleII::findOrder(int numCourses,
                                        vector<pair<int, int>> &prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>(0));

    // construct the course dependency graph
    for (auto p : prerequisites)
        graph[p.second].push_back(p.first);

    vector<bool> marked(numCourses, false);
    vector<bool> onStack(numCourses, false);
    bool hasCycle = false;

    for (int v = 0; v < numCourses; v++)
        if (!dfs(graph, marked, onStack, v)) {
            hasCycle = true;
            break;
        }

    vector<int> order;

    if (hasCycle)
        return order;

    vector<int> postorder;

    for (int i = 0; i < numCourses; i++)
        marked[i] = false;

    for (int v = 0; v < numCourses; v++)
        if (!marked[v])
            dfs(graph, marked, postorder, v);

    reverse(postorder.begin(), postorder.end());
    return postorder;
}

bool CourseScheduleII::dfs(vector<vector<int>> &graph, vector<bool> &marked,
                           vector<bool> &onStack, int v) {
    onStack[v] = true;
    marked[v] = true;

    for (auto w : graph[v]) {
        if (!marked[w]) {
            if (!dfs(graph, marked, onStack, w))
                return false;
        } else if (onStack[w])
            return false;
    }

    onStack[v] = false;
    return true;
}

void CourseScheduleII::dfs(vector<vector<int>> &graph, vector<bool> &marked,
                           vector<int> &postorder, int v) {
    marked[v] = true;

    for (auto w : graph[v]) {
        if (!marked[w])
            dfs(graph, marked, postorder, w);
    }

    postorder.push_back(v);
}
