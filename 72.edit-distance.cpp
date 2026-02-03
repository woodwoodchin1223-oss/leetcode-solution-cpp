/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> dp;
    int helper(int i, int j, string& word1, string& word2) {
        if (i == word1.size() && j < word2.size()) {
            return word2.size() - j;
        }
        if (j == word2.size() && i < word1.size()) {
            return word1.size() - i;
        }
        if (i == word1.size() && j == word2.size()) return 0;

        if (dp[i][j] != -1) return dp[i][j];
        if (word1[i] == word2[j]) {
            dp[i][j] = helper(i + 1, j + 1, word1, word2);
            return dp[i][j];
        } else {
            int ret1 = 1 + helper(i + 1, j, word1, word2);
            int ret2 = 1 + helper(i, j + 1, word1, word2);
            int ret3 = 1 + helper(i + 1, j + 1, word1, word2);
            dp[i][j] = min(ret1, min(ret2, ret3));
            return dp[i][j];
        }
    }
    int minDistance(string word1, string word2) {
        if (word1.size() == 0) return word2.size();
        if (word2.size() == 0) return word1.size();
        dp.resize(word1.size(), vector<int>(word2.size(), -1));
        return helper(0, 0, word1, word2);
    }
};
// @lc code=end

