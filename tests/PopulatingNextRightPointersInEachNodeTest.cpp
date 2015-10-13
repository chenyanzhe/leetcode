#include "catch.hpp"

#include "PopulatingNextRightPointersInEachNode.hpp"

#include <queue>
using namespace std;

TEST_CASE("Populating Next Right Pointers in Each Node") {
    PopulatingNextRightPointersInEachNode s;

    TreeLinkNode *root = nullptr;

    SECTION("Sample test") {
        /*
         *     1
         *    / \
         *   2   3
         *  / \ / \
         * 4  5 6  7
         *
         * after connecting
         *
         *      1 -> NULL
         *    /  \
         *   2 -> 3 -> NULL
         *  / \  / \
         * 4->5->6->7 -> NULL
         */
        TreeLinkNode *_4 = new TreeLinkNode(4);
        TreeLinkNode *_5 = new TreeLinkNode(5);
        TreeLinkNode *_6 = new TreeLinkNode(6);
        TreeLinkNode *_7 = new TreeLinkNode(7);
        TreeLinkNode *_2 = new TreeLinkNode(2, _4, _5);
        TreeLinkNode *_3 = new TreeLinkNode(3, _6, _7);
        TreeLinkNode *_1 = new TreeLinkNode(1, _2, _3);
        root = _1;

        s.connect(root);

        // check tree structure remains
        REQUIRE(root == _1);
        REQUIRE(root->left == _2); REQUIRE(root->right == _3);
        REQUIRE(_2->left == _4); REQUIRE(_2->right == _5);
        REQUIRE(_3->left == _6); REQUIRE(_3->right == _7);

        // check nodes in each level are linked
        REQUIRE(_1->next == nullptr);
        REQUIRE(_2->next == _3); REQUIRE(_3->next == nullptr);
        REQUIRE(_4->next == _5); REQUIRE(_5->next == _6);
        REQUIRE(_6->next == _7); REQUIRE(_7->next == nullptr);
    }

    // free tree
    TreeLinkNode *p = root;
    if (p == nullptr) return;

    queue<TreeLinkNode *> *q = new queue<TreeLinkNode *>();
    q->push(p);

    while (!q->empty()) {
        p = q->front();
        q->pop();
        if (p->left != nullptr)
            q->push(p->left);
        if (p->right != nullptr)
            q->push(p->right);
        delete p;
    }
    delete q;
}