/*
You are given Q queries and have to perform the following operations:
add x - add element x at the end of the queue
remove - delete the front element of the queue, if the queue is not empty
print - print the element at the first position, if the queue is not empty, otherwise print 0
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

        queue<int>qu;

        while(q--){
            string s;
            cin>>s;

            if(s=="add"){
                int x;
                cin>>x;
                qu.push(x);
            }else if(s=="remove"){
                if(!qu.empty()){
                    qu.pop();
                }
            }else{
                if(!qu.empty()){
                    cout<<qu.front()<<'\n';
                }else{
                    cout<<"0\n";
                }
            }
        }
    }
    return 0;
}
