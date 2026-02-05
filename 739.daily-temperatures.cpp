/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ret;
        stack<int> s;
        stack<int> mon;
        int tmp;
        for (auto current = temperatures.end(); current != temperatures.begin();) {
            current -= 1;
            tmp = 0;
            while (mon.size() > 0 && mon.top() <= *current) {
                int t = mon.top();
                if (t > *current) {
                    break;
                } else {
                    tmp += s.top();
                    mon.pop();
                    s.pop();
                }
            }
            if (mon.size() > 0 && mon.top() > *current) {
                tmp += 1;
            } else {
                tmp = 0;
            }
            mon.push(*current);
            s.push(tmp);
            ret.push_back(tmp);
        }
        vector<int> ans;
        for (auto current = ret.end(); current != ret.begin(); ) {
            current--;
            ans.push_back(*current);
        }
        return ans;
    }
};
// @lc code=end

