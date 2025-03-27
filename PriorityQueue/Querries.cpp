/*
Description
You are given Q queries and have to perform the following operations:
add x - add element x at the top of Priority Queue
remove - delete top element of the Priority Queue, if Priority Queue is not empty
print - print the element at top of the Priority Queue, if Priority Queue is not empty, otherwise print 0

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

        priority_queue<int> pq;

        while(q--){

            string s;
            cin>>s;
            if(s=="add"){
                int x;
                cin>>x;
                pq.push(x);
            }else if(s=="remove"){
                if(!pq.empty())
                pq.pop();
            }else{
                if(!pq.empty()){
                int top = pq.top();
                cout<<top<<"\n";}
                else cout<<"0\n";
            }
        }
    }
    return 0;
}
