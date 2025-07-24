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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode* hB = headB;
        ListNode* hA = headA;
        while(headA!=headB){
          headA = (headA)? headA->next:hB;
          headB = (headB)? headB->next:hA;
        }
        return headA;
    }
};
