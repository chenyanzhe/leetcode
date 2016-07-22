#ifndef GRAY_CODE_HPP_
#define GRAY_CODE_HPP_

#include <vector>

using namespace std;

class GrayCode {
public:
    vector<int> grayCode(int n);

private:
    void helper(int n, vector<int> &res);
};

#endif // GRAY_CODE_HPP_
