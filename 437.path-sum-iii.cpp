/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
    void helper(unordered_map<long, int>& prevSums, int targetSum, TreeNode* node, long currentSum) {
        if (node == nullptr) return;

        if (prevSums.find(currentSum) == prevSums.end()) prevSums[currentSum] = 1;
        else prevSums[currentSum] += 1;

        currentSum += node->val;
        if (prevSums.find(currentSum - targetSum) != prevSums.end()) {
            ans += prevSums[currentSum - targetSum];
        }
        helper(prevSums, targetSum, node->left, currentSum);
        helper(prevSums, targetSum, node->right, currentSum);
        currentSum -= node->val;
        prevSums[currentSum] -= 1;
        if (prevSums[currentSum] == 0) prevSums.erase(currentSum);
        return;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, int> prevSums;
        ans = 0;
        helper(prevSums, targetSum, root, 0);
        return ans;
    }
};
// @lc code=end

