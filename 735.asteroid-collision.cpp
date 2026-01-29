/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ret;
        for (int i = 0; i < asteroids.size(); i++) {
            int current = asteroids.at(i);
            if (ret.size() == 0) {
                ret.push_back(current);
            } else {
                while (ret.size() > 0 && ret.at(ret.size() - 1) > 0 && current < 0) {
                    int prev = ret.at(ret.size() - 1);
                    if (abs(prev) == abs(current)) {
                        current = 0;
                        ret.pop_back();
                        break;
                    } else if (abs(prev) > abs(current)) {
                        current = 0;
                        break;
                    } else {
                        ret.pop_back();
                    }
                }

                if (current != 0) ret.push_back(current);
            }
        }
        return ret;
    }
};
// @lc code=end

