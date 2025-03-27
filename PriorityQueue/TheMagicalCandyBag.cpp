/*
You have N magical candy bag. The i-th bag contains Ai candies. In each minute you can eat all the candies, Ai of one bag, after that, the candies become [Ai / 2] where [x] is the greatest integer less than x.
You have K minutes, find the maximum number of candies you can eat.
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
        int n,k;
        cin>>n>>k;
        priority_queue<int>pq;
        for(int i=0;i<n;i++) {
            int x;
            cin>>x;
            pq.push(x);
        }
        int candy_cnt = 0;
        while(k--){
            if(!pq.empty()){
                int top = pq.top();
                candy_cnt += top;
                pq.pop();
                pq.push(top/2);
            }else{
                break;
            }
        }
        cout<<candy_cnt<<'\n';        
    }
    return 0;
}
