#ifndef COURSE_SCHEDULE_HPP_
#define COURSE_SCHEDULE_HPP_

#include <vector>
#include <utility>
using namespace std;

class CourseSchedule {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites);
private:
    bool canFinishDFS(vector<vector<int>> &graph, vector<int> &visit, int i);
};

#endif // COURSE_SCHEDULE_HPP_
