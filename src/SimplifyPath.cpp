#include "SimplifyPath.hpp"

#include <stack>
using namespace std;

string SimplifyPath::simplifyPath(string path)
{
	vector<string> tokens;

	tokenize(path, tokens);

	string result = "";

	stack<string> ops;

	for (auto t : tokens) {
		if (t == "..") {
			if (!ops.empty()) ops.pop();
		} else if (t != ".") {
			ops.push(t);
		}
	}

	if (ops.empty()) return "/";

	while (!ops.empty()) {
		string t = ops.top();
		ops.pop();
		result = "/" + t + result;
	}

	return result;
}

void SimplifyPath::tokenize(const string& path, vector<string>& tokens)
{
	int i = 0, j = 0;
	int sz = path.size();

	if (sz == 0) return;

	while (i < sz) {
		while (i < sz && path[i] == '/')
			i++;
		j = i;
		while (j < sz && path[j] != '/')
			j++;
		if (i < sz)
			tokens.push_back(path.substr(i, j - i));
		i = j + 1;
	}
}
