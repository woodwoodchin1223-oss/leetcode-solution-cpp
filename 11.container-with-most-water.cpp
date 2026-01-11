/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int ret = 0;
        while (l < r) {
            ret = max(ret, (r - l)* min(height[r], height[l]));
            if (height[l] < height[r]) {
                l ++;
            } else {
                r --;
            }
        }
        return ret;
    }
};
// @lc code=end

