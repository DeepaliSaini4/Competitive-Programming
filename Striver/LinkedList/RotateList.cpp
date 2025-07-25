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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;  
       


        ListNode* temp = head;
        int size = 1;
        while(temp->next){
            size++;
            temp=temp->next;
        }
        k = k%size;
        temp = head;
        if(k==0) return head;

        int go = size - k;
        while(--go){
            temp=  temp->next;
        } 

        ListNode* n = temp->next;

        temp->next= NULL;
        temp = n;
        while(n->next){
            n = n->next;
        }
        n->next=head;
        return temp;
    }
};
