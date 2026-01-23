/*
 * @lc app=leetcode id=1679 lang=cpp
 *
 * [1679] Max Number of K-Sum Pairs
 */

// @lc code=start
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int sum = k;
        unordered_map<int, int> map;
        unordered_set<int> visited;
        for (int i = 0; i < nums.size(); i++) {
            auto v = map.find(nums.at(i));
            if (v != map.end()) {
                v->second += 1;
            } else {
                map[nums.at(i)] = 1;
                
            }
        }
        int ans = 0;
        for (auto kv = map.begin(); kv != map.end(); kv++) {
            int k = kv->first;
            int v = kv->second;
            int target_k = sum - k;
            auto target = map.find(target_k);
            if (target != map.end()) {
                if (visited.find(target->first) == visited.end()) {
                    if (k == target->first) {
                        ans += v / 2;
                    } else {
                        ans += min(v, target->second); 
                    }
                    visited.insert(target->first);
                    visited.insert(kv->first);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

