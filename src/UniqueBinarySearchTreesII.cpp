#include "UniqueBinarySearchTreesII.hpp"

vector<TreeNode *> UniqueBinarySearchTreesII::generateTrees(int n) {
    if (n <= 0) return vector<TreeNode *>();

    return generateTreesRec(1, n);
}

vector<TreeNode *> UniqueBinarySearchTreesII::generateTreesRec(int begin,
                                                               int end) {
    vector<TreeNode *> ret;

    if (begin > end) {
        ret.push_back(nullptr);
        return ret;
    }

    vector<TreeNode *> left;
    vector<TreeNode *> right;

    for (int i = begin; i <= end; i++) {
        left = generateTreesRec(begin, i - 1);
        right = generateTreesRec(i + 1, end);

        for (auto l : left)
            for (auto r : right) {
                TreeNode *root = new TreeNode(i);
                root->left = l;
                root->right = r;
                ret.push_back(root);
            }
    }

    return ret;
}

vector<TreeNode *> UniqueBinarySearchTreesII::generateTreesDP(int n) {
    if (n == 0)
        return vector<TreeNode *>();

    vector<vector<vector<TreeNode *>>> dp(n + 2, vector<vector<TreeNode *>>(n + 2,
                                                                            vector<TreeNode *>()));

    for (int i = 1; i <= n + 1; i++) {
        dp[i][i].push_back(new TreeNode(i));
        dp[i][i - 1].push_back(nullptr);
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n + 1 - l; i++) {
            int j = i + l - 1;

            for (int k = i; k <= j; k++) {
                for (auto left : dp[i][k - 1]) {
                    for (auto right : dp[k + 1][j]) {
                        TreeNode *root = new TreeNode(k);
                        root->left = left;
                        root->right = right;
                        dp[i][j].push_back(root);
                    }
                }
            }
        }
    }

    return dp[1][n];
}

