/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution {
public:
    unordered_set<int> visited;
    int ret;
    int findCircleNum(vector<vector<int>>& isConnected) {
        ret = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            if (visited.find(i) == visited.end()) {
                traverse(i, isConnected);
                ret += 1;
            }
        }
        return ret;
    }
    
    void traverse(int node, vector<vector<int>>& isConnected) {
        visited.insert(node);
        for (int i = 0; i < isConnected[node].size(); i++) {
            if (visited.find(i) == visited.end() && isConnected[node][i] == 1) {
                traverse(i, isConnected);
            }
        }
    }
};
// @lc code=end

