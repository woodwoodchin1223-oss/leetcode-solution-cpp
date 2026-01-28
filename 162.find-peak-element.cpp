/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
    int getIndex(int index, int size) {
        if (index == -1) return size - 1;
        if (index == size) return 0;
        return index; 
    }
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            int lindex = getIndex(mid - 1, nums.size());
            int mindex = getIndex(mid, nums.size());
            int rindex = getIndex(mid + 1, nums.size());
            if (nums[mindex] > nums[lindex] && nums[mindex] > nums[rindex]) {
                return mid;
            }
            if (nums[mindex] <= nums[lindex] && nums[mindex] <= nums[rindex]) {
                left = mid + 1;
                continue;
            }
            if (nums[mindex] <= nums[lindex] && nums[mindex] >= nums[rindex]) {
                right = mid - 1;
                continue;
            }
            if (nums[mindex] >= nums[lindex] && nums[mindex] <= nums[rindex]) {
                left = mid + 1;
                continue;
            }
            if (nums[mindex] == nums[lindex] && nums[mindex] > nums[rindex]) {
                right = mid - 1;
                continue;
            }
            if (nums[mindex] > nums[lindex] && nums[mindex] == nums[rindex]) {
                left = mid + 1;
                continue;
            }
        }
        return left;
    }
};
// @lc code=end

