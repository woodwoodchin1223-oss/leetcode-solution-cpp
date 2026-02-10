/*
 * @lc app=leetcode id=2352 lang=cpp
 *
 * [2352] Equal Row and Column Pairs
 */

// @lc code=start
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> m;
        for (int i = 0; i < grid.size(); i++) {
            string current = "";
            for (int j = 0; j < grid[i].size(); j++) {
                current += (to_string(grid[i][j]) + ",");
            }
            if (m.find(current) != m.end()) m[current] += 1;
            else m[current] = 1;
        }
        unordered_map<string, int> n;
        for (int i = 0; i < grid[0].size(); i++) {
            string current = "";
            for (int j = 0; j < grid.size(); j++) {
                current += (to_string(grid[j][i]) + ",");
            }
            if (n.find(current) != n.end()) n[current] += 1;
            else n[current] = 1;
        }

        int ans = 0;
        for (auto current = m.begin(); current != m.end(); current++) {
            if (n.find(current->first) != n.end()) {
                auto ccurrent = n.find(current->first);
                ans += current->second * ccurrent->second;
            }
        }
        return ans;
    }
};
// @lc code=end

