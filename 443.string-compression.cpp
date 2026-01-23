/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start
class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;
        for (int i = 0; i < chars.size();) {
            char c = chars.at(i);
            int count = 0;
            while (i < chars.size() && chars.at(i) == c) {
                count += 1;
                i += 1;
            }
            chars[ans] = c;
            ans += 1;
            if (count == 1) continue;
            for (char cc : to_string(count)) {
                chars[ans] = cc;
                ans += 1;
            }
            
        }
        return ans;
    }
};
// @lc code=end

