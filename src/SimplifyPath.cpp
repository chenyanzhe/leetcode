#include "SimplifyPath.hpp"

#include <stack>

using namespace std;

string SimplifyPath::simplifyPath(string path) {
    string ret;
    vector<string> dirs;
    stack<string> ops;

    splitPath(path, dirs);

    for (auto d : dirs) {
        if (d == ".") continue;
        if (d == "..") {
            if (!ops.empty()) ops.pop();
        } else ops.push(d);
    }

    if (ops.empty()) return "/";

    while (!ops.empty()) {
        ret = "/" + ops.top() + ret;
        ops.pop();
    }
    return ret;
}

void SimplifyPath::splitPath(string &path, vector<string> &dirs) {
    int a = 0, b = 0, n = path.size();
    while (a < n) {
        while (a < n && path[a] == '/') a++;
        if (a == n) break;
        b = a + 1;
        while (b < n && path[b] != '/') b++;
        dirs.push_back(path.substr(a, b - a));
        a = b;
    }
}
