#ifndef SIMPLIFY_PATH_HPP_
#define SIMPLIFY_PATH_HPP_

#include <string>
#include <vector>

using namespace std;

class SimplifyPath {
public:
    string simplifyPath(string path);

private:
    void splitPath(string &path, vector<string> &dirs);
};

#endif // SIMPLIFY_PATH_HPP_
