/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k = 1;
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
            ans = max(ans, right - left - 1);
        }
        return ans;
    }
};
// @lc code=end

