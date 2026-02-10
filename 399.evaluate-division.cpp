/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, pair<string, double>> dsu;
        for (int i = 0; i < equations.size(); i++) {
            vector<string> equation = equations[i];
            double value = values[i];
            string dividend = equation[0];
            string divisor = equation[1];
            un(dsu, dividend, divisor, value);
        }
        vector<double> ret;
        for (int i = 0; i < queries.size(); i++) {
            string divd = queries[i][0];
            string divs = queries[i][1];
            if (dsu.find(divd) == dsu.end() || dsu.find(divs) == dsu.end()) {
                ret.push_back(-1.0);
                continue;
            }
            auto current1 = find(dsu, divd);
            auto current2 = find(dsu, divs);
            if (current1.first != current2.first) ret.push_back(-1.0);
            else ret.push_back(current1.second / current2.second);
        }
        return ret;
    }

    pair<string, double> find(unordered_map<string, pair<string, double>>& dsu, string& nodeId) {
        if (dsu.find(nodeId) == dsu.end()) {
            pair<string, double> p(nodeId, 1.0);
            dsu[nodeId] = p;
        }
        pair<string, double> p = dsu[nodeId];
        if (p.first != nodeId) {
            pair<string, double> pp = find(dsu, p.first);
            pair<string, double> tp(pp.first, pp.second * p.second);
            dsu[nodeId] = tp;
        }
        return dsu[nodeId];
    }

    void un(unordered_map<string, pair<string, double>>& dsu, string& dividend, string& divisor, double value) {
        pair<string, double> dividendEntry = find(dsu, dividend);
        pair<string, double> divisorEntry = find(dsu, divisor);
        string dividendGid = dividendEntry.first;
        string divisorGid = divisorEntry.first;
        double dividendWeight = dividendEntry.second;
        double divisorWeight = divisorEntry.second;
        if (dividendGid != divisorGid) {
            pair<string, double> p(divisorGid, divisorWeight * value / dividendWeight);
            dsu[dividendGid] = p;
        }
    }
};
// @lc code=end

