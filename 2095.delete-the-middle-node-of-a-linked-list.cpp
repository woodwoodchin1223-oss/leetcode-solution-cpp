/*
 * @lc app=leetcode id=2095 lang=cpp
 *
 * [2095] Delete the Middle Node of a Linked List
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
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr) {
            if (fast->next == nullptr) {
                break;
            } else if (fast->next!= nullptr && fast->next->next == nullptr) {
                slow = slow->next;
                break;
            } else {
                slow = slow->next;
                fast = fast->next->next;
            }
        }
        ListNode* node = head;
        while (node->next != slow) {
            node = node->next;
        }
        node->next = node->next->next;
        return head;
    }
};
// @lc code=end

