/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        int ret = INT_MIN;
        int len = 0;
        ListNode* node = head;
        while (node != nullptr) {
            len += 1;
            node = node->next;
        }
        node = head;
        unordered_map<int, int> records;
        int count = 0;
        while (node != nullptr) {
            int index = count;
            if (count > (len / 2 - 1)) {
                index = len - count - 1;
            }

            if (records.find(index) == records.end()) records[index] = node->val;
            else {
                records[index] = records[index] + node->val;
                int current = records[index];
                ret = max(ret, current);
            }
            node = node->next;
            count += 1;
        }
        return ret;
    }
};
// @lc code=end

