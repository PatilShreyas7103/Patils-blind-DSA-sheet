// 968. Binary Tree Cameras

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int cameras = 0;

    int dfs(TreeNode* root) {
        if (!root) return 2;  // null nodes are covered

        int left = dfs(root->left);
        int right = dfs(root->right);

        if (left == 0 || right == 0) {
            cameras++;
            return 1;  // place camera here
        }

        if (left == 1 || right == 1) {
            return 2;  // covered
        }

        return 0;  // not covered
    }

    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) {
            cameras++;
        }
        return cameras;
    }
};