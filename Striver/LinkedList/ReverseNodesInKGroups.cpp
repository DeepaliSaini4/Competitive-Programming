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
    //Reverse function returns the head of the newly reversed linked list
    ListNode* Reverse(ListNode* s,ListNode* e){
        ListNode* curr = s;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* stop = e->next;//the node where we need to stop the reversal being carried for the node list
        while(curr!=stop){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return e;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* start = head;
        ListNode* end = head;
        ListNode* prevtail = dummy;
        while(true){
            int count = 1;
            while(count<k && end){
                end=end->next;
                count++;
            }
            if(!end) break;

            ListNode* nextgroup = end->next;
            ListNode* newhead = Reverse(start,end);
            prevtail ->next = newhead;
            start->next = nextgroup;
            prevtail = start;
            start = end = nextgroup;

        }
        return dummy->next;
    }
};
