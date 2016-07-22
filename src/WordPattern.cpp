#include "WordPattern.hpp"

#include <unordered_map>
#include <sstream>

using namespace std;

bool WordPattern::wordPattern(string pattern, string str) {
    unordered_map<char, string> p2w;
    unordered_map<string, char> w2p;
    stringstream in(str);
    string w;

    for (auto p : pattern) {
        if (!(in >> w))
            return false;

        if (p2w.count(p) && p2w[p] != w)
            return false;

        if (w2p.count(w) && w2p[w] != p)
            return false;

        p2w[p] = w;
        w2p[w] = p;
    }

    return !(in >> w);
}
