#ifndef VERIFY_PREORDER_SEQUENCE_IN_BINARY_SEARCH_TREE_HPP_
#define VERIFY_PREORDER_SEQUENCE_IN_BINARY_SEARCH_TREE_HPP_

#include <vector>

using namespace std;

class VerifyPreorderSequenceInBinarySearchTree {
public:
    bool verifyPreorder(vector<int> &preorder);

private:
    bool verifyPreorder_Stack(vector<int> &preorder);

    bool verifyPreorder_Inplace(vector<int> &preorder);
};

#endif // VERIFY_PREORDER_SEQUENCE_IN_BINARY_SEARCH_TREE_HPP_