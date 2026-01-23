/*
 * @lc app=leetcode id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 */

// @lc code=start
class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a') return true;
        if (c == 'e') return true;
        if (c == 'i') return true;
        if (c == 'o') return true;
        if (c == 'u') return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int ans = 0;
        int left = 0;
        int right = 0;
        int tmp = 0;
        while (left <= right && right < s.size()) {
            if (right - left < k) {
                if (isVowel(s[right])) {
                    tmp += 1;
                    ans = max(ans, tmp);
                }
                right += 1;
            } else {
                if (isVowel(s[left])) {
                    tmp -= 1;
                }
                left += 1;
            }
        }
        return ans;
    }
};
// @lc code=end

