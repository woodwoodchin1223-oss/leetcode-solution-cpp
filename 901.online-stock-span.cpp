/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start
class StockSpanner {
public:
    stack<int> s;
    vector<int> v;
    StockSpanner() { 
    }
    
    int next(int price) {
        if (s.size() == 0) {
            s.push(price);
            v.push_back(1);
            return 1;
        } else {
            int ret = 1;
            while (s.size() > 0 && s.top() <= price) {
                s.pop();
                ret += v.at(v.size() - 1);
                v.pop_back();
            }
            s.push(price);
            v.push_back(ret);
            return ret;
        }
    }
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

