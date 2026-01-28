/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return qselect(nums, nums.size() - k + 1);
    }
    int qselect(vector<int>& nums, int k) {
        int pivot = nums[rand() % nums.size()];
        vector<int> left;
        vector<int> mid;
        vector<int> right;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) {
                left.push_back(nums[i]);
            } else if (nums[i] > pivot) {
                right.push_back(nums[i]);
            } else {
                mid.push_back(nums[i]);
            }
        }
        if (left.size() >= k) return qselect(left, k);
        if ((left.size() + mid.size()) < k) return qselect(right, k - left.size() - mid.size());
        return pivot;
    }
};
// @lc code=end

