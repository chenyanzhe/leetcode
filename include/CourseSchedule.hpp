#ifndef COURSE_SCHEDULE_HPP_
#define COURSE_SCHEDULE_HPP_

#include <vector>
#include <utility>

using namespace std;

class CourseSchedule {
public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites);

private:
    bool dfs(vector<vector<int>> &graph, vector<bool> &marked,
             vector<bool> &onStack, int v);
};

#endif // COURSE_SCHEDULE_HPP_
