/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        vector<bool> hasMax;
        vector<bool> hasMin;
        int pivot = nums[nums.size() - 1];
        for (int i = 0; i < nums.size(); i++) {
            hasMax.push_back(false);
            hasMin.push_back(false);
        }
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (pivot > nums[i]) {
                hasMax[i] = true;
            } else if (pivot < nums[i]) {
                pivot = nums[i];
            }
        }

        pivot = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (pivot < nums[i]) {
                hasMin[i] = true;
            } else if (pivot > nums[i]) {
                pivot = nums[i];
            }
        }
        
        bool res = false;
        for (int i = 1; i < nums.size() - 1; i++) {
            if (hasMin[i] && hasMax[i]) res = true;
        }
        return res;
    }
};
// @lc code=end

