/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int multi = 1;
        int zeroNum = 0;
        for (int& n : nums) {
            if (n == 0) {
                zeroNum += 1;
                continue;
            }
            multi *= n;
        }
        if (zeroNum >= 2) {
            for (int & n : nums) {
                res.push_back(0);
            }
            return res;
        }

        if (zeroNum == 0) {
            for (int & n : nums) {
                res.push_back(multi / n);
            }
            return res;
        }

        for (int & n : nums) {
            if (n == 0) res.push_back(multi);
            else res.push_back(0);
        }

        return res;
    }
};
// @lc code=end

