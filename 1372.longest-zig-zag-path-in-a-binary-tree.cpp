/*
 * @lc app=leetcode id=1372 lang=cpp
 *
 * [1372] Longest ZigZag Path in a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;
    void helper(TreeNode* node, int t, int prevD) {
        if (node == nullptr) {
            return;
        }
        ans = max(ans, t);
        // 0 left
        // 1 right
        if (prevD == 1) {
            helper(node->right, 1, 1);
            helper(node->left, t + 1, 0);
        } else if (prevD == 0) {
            helper(node->right, t + 1, 1);
            helper(node->left, 1, 0);
        } else {
            helper(node->right, t + 1, 1);
            helper(node->left, t + 1, 0);
        }
    }
    int longestZigZag(TreeNode* root) {
        ans = 0;
        helper(root, 0, -1);
        return ans;
    }
};
// @lc code=end

