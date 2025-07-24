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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp = head;
        int cnt = 0;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        temp = head;
        int ni = cnt - n-1;
        if(n==cnt){
            head = head->next;
            return head;
        }
        while(ni--){
            temp = temp->next;
        }
        if(temp->next->next) temp->next=temp->next->next;
        else temp->next = NULL;
        return head;
    }
};
