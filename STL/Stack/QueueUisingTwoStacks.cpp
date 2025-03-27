/*
Implement a queue using 2 stacks. You will be given the following type of Q queries:
push x - add x to the queue
pop - pop the front element of the queue, you also have to print the element you have popped.
front - find the element at the front of the queue
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        int q;
        cin>>q;

        stack<int>s1;
        stack<int>s2;

        while(q--){
            string s;
            cin>>s;

            if(s=="push"){
                int x;
                cin>>x;
                s1.push(x);
            }else if(s == "pop"){
                if(!s2.empty()){
                    int popped = s2.top();
                    cout<<popped<<'\n';
                    s2.pop();
                }else{
                    while(!s1.empty()){
                        s2.push(s1.top());
                        s1.pop();
                    }
                    if(!s2.empty()){
                        int popped = s2.top();
                        cout<<popped<<'\n';
                    s2.pop();}
                }
            }else{
                if(!s2.empty()){
                    cout<<s2.top()<<'\n';
                }else{
                    while(!s1.empty()){
                        s2.push(s1.top());
                        s1.pop();
                    }
                    if(!s2.empty()) cout<<s2.top()<<'\n';
                }
            }
        }
    }
    return 0;
}
