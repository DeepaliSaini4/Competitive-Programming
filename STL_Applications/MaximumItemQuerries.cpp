// Problem: Given a shop with N items, where each item is indexed by i and has a price Pi. The task is to determine the maximum number of items that can be purchased.
//But now you are given M queries each carry the budget Bj.

#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int n;
    cin>>n;
    
    int prices[n];
    for(int i=0;i<n;i++) cin>>prices[i];
    
    sort(prices,prices+n);
    
    //prefix sum array
    for(int i=1;i<n;i++) prices[i]+=prices[i-1];
    
    int q;
    cin>>q;
    while(q--){
        int b;
        cin>>b;
        cout<<upper_bound(prices,prices+n,b)-prices<<'\n';
    }
    return 0;
}
// n+m logn
