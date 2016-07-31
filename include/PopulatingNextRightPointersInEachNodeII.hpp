#ifndef POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_II_HPP_
#define POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_II_HPP_

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;

    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}

    TreeLinkNode(int x, TreeLinkNode *l, TreeLinkNode *r) : val(x), left(l),
                                                            right(r), next(nullptr) {}
};

class PopulatingNextRightPointersInEachNodeII {
public:
    void connect(TreeLinkNode *root);

private:
    void connect_Iterative(TreeLinkNode *root);

    void connect_Recursive(TreeLinkNode *root);
};

#endif // POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_II_HPP_
