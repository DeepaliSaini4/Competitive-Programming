/*
the lower bound of x, which means finding the first index such that the element at that index is ">=x".
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

int arr[10001];
int x,n;

bool check(int mid){
    return arr[mid]>=x;
}

void solver(){
    cin>>n>>x;
    for(int i=0;i<n;i++) cin>>arr[i];
    
    int lo=0;
    int hi=n-1;
    int ans =-1;
    
    while(lo<=hi){
        
        int mid = lo+((hi-lo)/2);
        if(check(mid)==1){
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    cout<<ans<<'\n';
}

signed main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int t;
    cin>>t;
    
    while(t--) solver();
    
    return 0;
}
