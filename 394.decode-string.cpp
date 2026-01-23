/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution {
public:
    int index = 0;
    string decodeString(string s) {
        string ret = "";
        while (index < s.size() && s[index] != ']') {
            if (isalpha(s[index])) {
                ret += s[index];
                index += 1;
            } else {
                int cnt = 0;
                while (index < s.size() && isdigit(s[index])) {
                    cnt = cnt * 10 + (s[index] - '0');
                    index += 1;
                }
                index += 1;
                cout << cnt << endl;
                string sub = decodeString(s);
                for (int i = 0; i < cnt; i++) {
                    ret += sub;
                }
                index += 1;
            }
        }
        return ret;
    }
};
// @lc code=end

