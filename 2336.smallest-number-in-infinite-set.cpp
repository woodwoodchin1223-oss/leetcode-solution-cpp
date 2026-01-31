/*
 * @lc app=leetcode id=2336 lang=cpp
 *
 * [2336] Smallest Number in Infinite Set
 */

// @lc code=start
class SmallestInfiniteSet {
public:
    int current;
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> s;
    SmallestInfiniteSet() {
        current = 1;
    }
    
    int popSmallest() {
        if (!pq.empty()) {
            int ret = pq.top();
            pq.pop();
            s.erase(ret);
            return ret;
        }
        current += 1;
        return current - 1;
    }
    
    void addBack(int num) {
        if (num < current && s.find(num) == s.end()) {
            pq.push(num);
            s.insert(num);
        }
    }
};


/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @lc code=end

