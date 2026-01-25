/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution {
public:
    int caltime(vector<int>& piles, int speed) {
        int ret = 0;
        for (int p : piles) {
            if (p % speed == 0) ret += p / speed;
            else ret += (p / speed + 1);
        }
        return ret;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxP = 0;
        int minP = 1;
        for (int& p : piles) {
            maxP = max(maxP, p);
        }
        int left = 1;
        int right = maxP;
        while (left < right) {
            int mid = (left + right) / 2;
            int consume = caltime(piles, mid);
            if (consume > h) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
// @lc code=end

