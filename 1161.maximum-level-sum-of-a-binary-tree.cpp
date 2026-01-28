/*
 * @lc app=leetcode id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
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
    unordered_map<int, int> su;
    int max_depth = -1;
    void travel(TreeNode* node, int depth) {
        if (node == nullptr) return;
        max_depth = max(max_depth, depth);
        if (su.find(depth) == su.end()) {
            su[depth] = 0;
        }
        su[depth] += node->val;
        travel(node->left, depth + 1);
        travel(node->right, depth + 1);
    }

    int maxLevelSum(TreeNode* root) {
        int ans = INT_MIN;
        int ret = 0;
        travel(root, 1);
        for (int i = 1; i <= max_depth; i++) {
            auto current = su.find(i);
            if (current->second > ans) {
                ans = current->second;
                ret = current->first;
            }
        }
        return ret;
    }
};
// @lc code=end

