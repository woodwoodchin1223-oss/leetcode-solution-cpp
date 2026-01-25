/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    unordered_map<int, stack<TreeNode*>> rank;
    int maxDepth = 0;
    void helper(TreeNode* node, int row) {
        if (node == nullptr) return;
        if (rank.find(row) == rank.end()) {
            stack<TreeNode*> tmp;
            rank[row] = tmp;
        }
        maxDepth = max(maxDepth, row);
        auto current = rank.find(row);
        current->second.push(node);
        helper(node->left, row + 1);
        helper(node->right, row + 1);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (root == nullptr) {
            return ret;
        }
        helper(root, 0);
        for (int i = 0; i <= maxDepth; i++) {
            auto current = rank.find(i);
            ret.push_back((current->second).top()->val);
        }
        return ret;
    }
};
// @lc code=end

