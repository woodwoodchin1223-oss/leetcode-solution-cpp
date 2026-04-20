class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curEnd = 0;
        int curFar = 0;
        for (int i = 0; i < nums.size(); i++) {
            curFar = max(curFar, i + nums[i]);
            if (curEnd == i) {
                curEnd = curFar;
                if  (curEnd >= nums.size() - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};