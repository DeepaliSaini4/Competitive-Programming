/*
Given the heads of two singly linked lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return NULL.
*/

/////////APPROACH -1 O(N+M)
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* one = headA;
    ListNode* two = headB;
    ListNode* one2 = headA;
    ListNode* two2 = headB;

    while(one!=NULL && two!=NULL){
        one=one->next;
        two=two->next;
    }
    if(one==NULL){
        while(two!=NULL){
            two=two->next;
            two2=two2->next;
        }
        while(one2!=two2){
            one2=one2->next;
            two2=two2->next;
        }
        return one2;
    }else{
        while(one!=NULL){
            one=one->next;
            one2=one2->next;
        }
        while(one2!=two2){
            one2=one2->next;
            two2=two2->next;
        }
        return one2;
    }
}


ListNode* GetList(vector<int> &num) {
    ListNode* head = nullptr;

    if(num.empty()) {
        return head;
    }

    ListNode* cur = head;
    
    for(int i  = 0; i < (int)num.size(); i++) {
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
    
    return head;
}

pair<ListNode*, ListNode*> GetList(vector<int> listA, vector<int> listB, int skipA, int skipB) {
    ListNode* headA = GetList(listA);
    
    if(skipA == -1 && skipB == -1) {
        ListNode* headB = GetList(listB);
        return {headA, headB};    
    }

    vector<int> temp;
    for(int i = 0; i < skipB; i++) {
        temp.push_back(listB[i]);
    }

    ListNode* headB = GetList(temp);

    ListNode* curA = headA;
    for(int i = 0; i < skipA; i++) {
        curA = curA->next;
    }

    if(!headB) headB = curA;
    else {
        ListNode* curB = headB;
        while(curB->next) {
            curB = curB->next;
        }
        curB->next = curA;
    }

    return {headA, headB};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> listA(n);

    for(int i = 0; i < n; i++) {
        cin >> listA[i];
    }

    int m;
    cin >> m;

    vector<int> listB(m);

    for(int i = 0; i < m; i++) {
        cin >> listB[i];
    }

    int skipA, skipB;
    cin >> skipA >> skipB;

    pair<ListNode*,ListNode*> temp = GetList(listA, listB, skipA, skipB);

    ListNode* headA = temp.first;
    ListNode* headB = temp.second;

    ListNode* ansHead = getIntersectionNode(headA, headB);

    if(ansHead) {
        cout << ansHead->val << "\n";
    }
    else {
        cout << "-1\n";
    }

    return 0;
}
//APPROACH -2 (Short to write) O(n+m)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
   ListNode* one = headA, *two = headB;
   while(one!=two){
    one = (one == NULL) ? headB : one->next;
    two = (two == NULL) ? headA : two->next;
   }
   return one;
}
/*
To find the intersection node of two singly linked lists, use two pointers and traverse both lists simultaneously.
When one pointer reaches the end of its list, redirect it to the head of the other list.
By doing this, both pointers will traverse the same total length.
If the lists intersect, the pointers will eventually meet at the intersection node after at most two passes through the lists.
If there is no intersection, both one and two will become NULL after the second full traversal and the condition one != two becomes false (since NULL == NULL),
so the loop ends.
*/
