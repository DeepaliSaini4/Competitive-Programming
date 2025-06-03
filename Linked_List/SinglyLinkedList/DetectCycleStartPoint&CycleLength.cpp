/*
Given a non-empty linked list, your task is to find the cycle in the linked list. Return starting node of the cycle and length of the cycle. 
If there is no cycle, then return null as node and -1 as length.
*/

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


pair<ListNode*,int> cycleInLinkedList(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    bool iscycle = 0;

    while(fast!=NULL && slow!= NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow ->next;
            if(slow == fast){
                iscycle = 1;
                break;
            }
        }
    }
    if(!iscycle) return {NULL, -1};
    ListNode* temp = head;
    while(temp!=slow){
        slow = slow->next;
        temp = temp->next;
    }
    int length = 1;
    temp = temp->next;
    while(temp!=slow){
        temp = temp->next;
        length ++;
    }
    return {slow, length};
}


ListNode* GetList(int n, vector<int> &num, int lastLink) {
    ListNode* head = nullptr;

    if(num.empty()) {
        return head;
    }

    ListNode* cur = head;
    
    for(int i  = 0; i < n; i++) {
        ListNode* temp = new ListNode(num[i]);
        if(!cur) {
            cur = temp;
            head = cur;
        }
        else {
            cur->next = temp;
            cur = temp;
        }
    }

    if(lastLink) {
        ListNode* temp = head;
        for(int i = 0; i < lastLink - 1; i++) {
            temp = temp->next;
        }
        cur->next = temp;
    }
    
    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> num;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        num.push_back(x);
    }

    int lastLink;
    cin >> lastLink;

    ListNode* head = GetList(n, num, lastLink);

    pair<ListNode*,int> ans = cycleInLinkedList(head);

    cout << (ans.first ? ans.first->val : -1) << " " << ans.second << "\n";
    
    return 0;
}
//tc = O(Length of linked list)
//sc = O(1)
