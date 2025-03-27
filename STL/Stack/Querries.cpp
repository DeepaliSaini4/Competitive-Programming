/*
You are given Q queries and have to perform the following operations:

add x - add element x at the top of the stack

remove - delete the top element of the stack if the stack is not empty

print - print the element at the top, if the stack is not empty, otherwise print 0
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

        stack<int>st;

        while(q--){
            string s;
            cin>>s;

            if(s=="add"){
                int x;
                cin>>x;
                st.push(x);
            }else if(s=="remove"){
                if(!st.empty())
                st.pop();
            }else{
                if(!st.empty()){
                    cout<<st.top()<<'\n';
                }else{
                    cout<<"0\n";
                }
            }
        }
    }
    return 0;
}
