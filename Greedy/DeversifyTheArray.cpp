/*
You have given an array A. The diversity of the array A is defined as the number of pairs i, j, i < j such that Ai ≠ Aj.
You want to maximize the diversity of the array. For that, you are allowed to make at most K operations on it, in any of which, you can select a 
particular element and change its value to any integer in the range 1 to 109, both inclusive.
Find out the maximum diversity of the array that you can obtain.
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

        map<int,int>mp;

        priority_queue<pair<int,int>>pq;

        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            mp[x]++;
        }

        int ans = 1LL * n * (n-1)/2;
        
        for(auto it:mp){
            if(it.second > 1){
                pq.push({it.second, it.first});
                ans -= 1LL * it.second * (it.second-1)/2;
            }
        }

        for(int i=0;i<k;i++){
            if(pq.empty()) break;
            auto it = pq.top();
            pq.pop();
            ans += it.first -1 ;
            it.first--;
            if(it.first>1) pq.push(it);
        }

        cout<<ans<<'\n';
    }
    return 0;
}
