/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int ans = 0;
        while (left <= right && right < nums.size()) {
            if (nums[right] == 0) {
                k -= 1;
            }
            right += 1;
            while (k < 0) {
                if (nums[left] == 0) {
                    k += 1;
                }
                left += 1;
            }
            ans = max(ans, right - left);
        }
        return ans;
    }
};
// @lc code=end

