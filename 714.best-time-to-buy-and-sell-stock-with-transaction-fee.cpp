/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = INT_MIN;
        int sell = 0;
        for (int i = 0; i < prices.size(); i++) {
            int price = prices[i];
            buy = max(buy, sell - price);
            sell = max(sell, buy + price - fee);
        }
        return sell;
    }
};
// @lc code=end

