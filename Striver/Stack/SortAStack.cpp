/*You are given a stack of integers. Your task is to sort the stack in descending order using recursion,
\such that the top of the stack contains the greatest element. You are not allowed to use any loop-based sorting methods 
(e.g., quicksort, mergesort). You may only use recursive operations and the standard stack operations (push, pop, peek/top, and isEmpty).*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void insert(stack<int>&s,int val){
        //base case
        if(s.empty() || val>s.top()){
            s.push(val);
            return;
        }
        
        int curr = s.top();
        s.pop();
        insert(s,curr);
        push(curr);
        
    }
    void sortStack(stack<int> &st) {
        if(st.empty()) return;
        
        int top = s.top();
        
        st.pop();
        
        sortStack(s);
        
        insert(s,top);
    }
};
