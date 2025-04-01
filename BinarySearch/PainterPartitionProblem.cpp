/*
We have to paint n boards of length {A1, A2, ..., An}. There are k painters available, and each takes 1 unit time to paint 1 unit of the board.
The goal is to find the minimum time required to complete this task under the following constraints:
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,k;
vector<int>arr;

bool check(int x){
    int lastleft = 0;
    int needed = 0;
    for(int i=0;i<n;i++){
        if(lastleft>=arr[i]){
            lastleft-=arr[i];
        }else{
            needed++;
            lastleft = x-arr[i];
        }
    if(needed>k) return 0;
    }
     if(needed>k) return 0;
      return 1;
    
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;

    while(t--){
        cin>>n>>k;
        arr.resize(n);
        int lo = 0;
        int hi = 0;
        int ans =0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            lo = max(lo,arr[i]);
            hi +=arr[i];
        }
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(check(mid)){
                ans = mid;
                hi = mid -1;
            }else{
                lo = mid+1;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
