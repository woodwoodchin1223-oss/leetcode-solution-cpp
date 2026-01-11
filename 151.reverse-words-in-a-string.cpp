/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        vector<string> strs;
        string current = "";
        for (char& c : s) {
            if (c != ' ') {
                current += c;
            } else if (!current.empty()) {
                strs.push_back(current);
                current = "";
            }
        }
        if (current != "") strs.push_back(current);
        reverse(strs.begin(), strs.end());
        string ret = "";
        for (int i = 0; i < strs.size(); i++) {
            if (i == 0) ret += strs[i];
            else {
                ret += ' ';
                ret += strs[i];
            }
        }
        return ret;
    }
};
// @lc code=end

