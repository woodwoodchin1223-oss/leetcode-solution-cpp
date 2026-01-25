/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_set<TreeNode*> onePath;
    vector<TreeNode*> sPath;
    bool findPath(TreeNode* node, TreeNode* target) {
        if (node == nullptr) return false;
        if (target == node) {
            onePath.insert(node);
            return true;
        }
        bool ret = findPath(node->left, target) || findPath(node->right, target);
        if (ret == true) {
            onePath.insert(node);
        }
        return ret;
    }

    bool findPathStack(TreeNode* node, TreeNode* target) {
        if (node == nullptr) return false;
        if (target == node) {
            sPath.push_back(node);
            return true;
        }
        bool ret = findPathStack(node->left, target) || findPathStack(node->right, target);
        if (ret == true) {
            sPath.push_back(node);
        }
        return ret;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findPath(root, p);
        findPathStack(root, q);
        TreeNode* ret;
        for (auto current = sPath.rbegin(); current != sPath.rend(); current++) {
            auto found = onePath.find(*current); 
            if (found != onePath.end()) {
                ret = *found;
                continue;
            } else {
                break;
            }
        }
        return ret;
    }
};
// @lc code=end

