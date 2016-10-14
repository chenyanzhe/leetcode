#include "VerifyPreorderSequenceInBinarySearchTree.hpp"

#include <stack>
#include <climits>

using namespace std;

bool VerifyPreorderSequenceInBinarySearchTree::verifyPreorder(vector<int> &preorder) {
    return verifyPreorder_Inplace(preorder);
}

bool VerifyPreorderSequenceInBinarySearchTree::verifyPreorder_Stack(vector<int> &preorder) {
    int low = INT_MIN;
    stack<int> s;
    for (auto p : preorder) {
        if (p < low)
            return false;
        while (!s.empty() && s.top() < p) {
            low = s.top();
            s.pop();
        }
        s.push(p);
    }
    return true;
}

bool VerifyPreorderSequenceInBinarySearchTree::verifyPreorder_Inplace(vector<int> &preorder) {
    int low = INT_MIN;
    int stk = -1;
    for (auto p : preorder) {
        if (p < low)
            return false;
        while (stk >= 0 && preorder[stk] < p) {
            low = preorder[stk];
            stk--;
        }
        preorder[++stk] = p;
    }
    return true;
}
