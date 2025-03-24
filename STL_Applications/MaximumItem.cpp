/*
Q -> Given a shop with N items, where each item is indexed by i and has a price Pi. The task is to determine the maximum number of items that can be purchased given a budget B
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

using namespace std;


void solver(){
    int n,b;
    cin>>n>>b;
    
    int price[n];
    for(int i=0;i<n;i++) cin>>price[i];
    
    sort(price,price+n);
    
    int maxitem = 0 ;
    for(int i=0;i<n;i++){
        if(price[i]<=b){
            maxitem++;
            b-=price[i];
        }else{
            break;
        }
    }
    cout<<"Max items that can be purchased: "<<maxitem<<'\n';
    
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int t;
    cin>>t;
    while(t--) solver();
    return 0;
}
