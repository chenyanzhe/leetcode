#include "CourseSchedule.hpp"

bool CourseSchedule::canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
{
    vector<vector<int>> graph(numCourses, vector<int>(0));
    vector<int> visit(numCourses, 0);

    for (auto p : prerequisites)
        graph[p.second].push_back(p.first);

    for (int i = 0; i < numCourses; i++)
        if (!canFinishDFS(graph, visit, i)) return false;

    return true;
}

bool CourseSchedule::canFinishDFS(vector<vector<int>> &graph, vector<int> &visit, int i) {
    if (visit[i] == -1) return false;
    if (visit[i] == 1) return true;

    visit[i] = -1;
    for (auto n : graph[i])
        if (!canFinishDFS(graph, visit, n)) return false;
    visit[i] = 1;
    return true;
}
