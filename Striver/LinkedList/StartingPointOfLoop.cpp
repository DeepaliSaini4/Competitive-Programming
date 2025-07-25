/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                ListNode* entry = head;
                while (slow != entry) {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};/*
Once slow and fast meet inside the cycle, we reset one pointer to head, and move both one step at a time. The point where they meet again is the start of the cycle.

This works because of mathematical reasoning based on the lengths of the paths traveled by slow and fast.
*/
