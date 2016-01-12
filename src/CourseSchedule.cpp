#include "CourseSchedule.hpp"

bool CourseSchedule::canFinish(int numCourses,
                               vector<pair<int, int>>& prerequisites)
{
  vector<vector<int>> graph(numCourses, vector<int>(0));

  // construct the course dependency graph
  for (auto p : prerequisites) {
    graph[p.second].push_back(p.first);
  }

  vector<bool> marked(numCourses, false);
  vector<bool> onStack(numCourses, false);

  for (int v = 0; v < numCourses; v++)
    if (!dfs(graph, marked, onStack, v)) {
      return false;
    }

  return true;
}

bool CourseSchedule::dfs(vector<vector<int>>& graph, vector<bool>& marked,
                         vector<bool>& onStack, int v)
{
  onStack[v] = true;
  marked[v] = true;

  for (auto w : graph[v]) {
    if (!marked[w]) {
      if (!dfs(graph, marked, onStack, w)) {
        return false;
      }
    } else if (onStack[w]) {
      return false;
    }
  }

  onStack[v] = false;
  return true;
}
