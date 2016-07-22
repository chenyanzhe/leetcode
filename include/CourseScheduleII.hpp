#ifndef COURSE_SCHEDULE_II_HPP_
#define COURSE_SCHEDULE_II_HPP_

#include <vector>
#include <utility>

using namespace std;

class CourseScheduleII {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites);

private:
    bool dfs(vector<vector<int>> &graph, vector<bool> &marked,
             vector<bool> &onStack, int v);

    void dfs(vector<vector<int>> &graph, vector<bool> &marked,
             vector<int> &postorder, int v);
};

#endif // COURSE_SCHEDULE_II_HPP_
