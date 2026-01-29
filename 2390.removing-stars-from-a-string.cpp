/*
 * @lc app=leetcode id=2390 lang=cpp
 *
 * [2390] Removing Stars From a String
 */

// @lc code=start
class Solution {
public:
    string removeStars(string s) {
        string ret = "";
        vector<char> list;
        for (char c : s) {
            if (c == '*' && list.size() > 0) {
                list.pop_back();
            } else {
                list.push_back(c);
            }
        }
        for (char c : list) ret += c;
        return ret;
    }
};
// @lc code=end

