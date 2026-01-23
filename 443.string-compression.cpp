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
            char letter = chars[i];
            int count = 0;
            while (i < chars.size() && chars[i] == letter) {
                count += 1;
                i += 1;
            }
            chars[ans] = letter;
            ans += 1;

            if (count > 1) {
                for (char c : to_string(count)) {
                    chars[ans++] = c;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

