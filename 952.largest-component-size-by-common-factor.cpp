/*
 * @lc app=leetcode id=952 lang=cpp
 *
 * [952] Largest Component Size by Common Factor
 */

// @lc code=start
class DSU {
// just for fun
public:
    int n;
    vector<int> parents;
    vector<int> size;

    DSU(int n) {
        this->n = n;
        for (int i = 0; i <= n; i++) {
            this->parents.push_back(i);
            this->size.push_back(1);
        }
    }
    
    int un(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) return pa;
        int sa = this->size[pa];
        int sb = this->size[pb];
        if (sa > sb) {
            int tmp = pa;
            pa = pb;
            pb = tmp;
        }
        this->parents[pa] = pb;
        this->size[pa] += sb;
        return pb;
    }

    int find(int a) {
        int p = this->parents[a];
        if (p != a) {
            p = find(p);
            this->parents[a] = p;
        }
        return this->parents[a];
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int ans;
        int mn = INT_MIN;
        for (int& n : nums) mn = max(mn, n);
        DSU dsu(mn);
        for (int& n : nums) {
            for (int i = 2; i <= sqrt(n); i++) {
                if (n % i == 0) {
                    dsu.un(i, n);
                    dsu.un(n / i, n);
                }
            }
        }
        unordered_map<int, int> m;
        for (int& n : nums) {
            int p = dsu.find(n);
            if (m.find(p) == m.end()) {
                m[p] = 1;
            } else {
                m[p] += 1;
            }
        }
        ans = INT_MIN;
        for (auto current = m.begin(); current != m.end(); current++) {
            ans = max(ans, current->second);
        }
        return ans;
    }
};
// @lc code=end

