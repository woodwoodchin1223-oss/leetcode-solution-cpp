/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    unordered_map<int ,int> m;
    int rob(vector<int>& nums) {
        return helper(nums, nums.size() - 1);
    }

    int helper(vector<int>& nums, int k) {
        if (m.find(k) != m.end()) return m.find(k)->second;
        if (k == 0) return nums[0];
        if (k == 1) return max(nums[0], nums[1]);
        int ret1 = helper(nums, k - 2) + nums[k];
        int ret2 = helper(nums, k - 1);
        m[k] = max(ret1, ret2);
        return m[k];
    }
};
// @lc code=end

