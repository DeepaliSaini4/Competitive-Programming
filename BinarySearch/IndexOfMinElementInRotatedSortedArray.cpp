//Q -> Given a rotated sorted array with distinct elements, find the index of the minimum element in the array.

#include<bits/stdc++.h>
using namespace std;

#define int long long 
int n;
int arr[1010];

bool check(int mid){
    return (arr[mid] <= arr[n-1]);
}

void solver(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    
    int lo = 0;
    int hi = n-1;
    int ans =-1;
    
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(check(mid)){
            ans = mid;
            hi=mid-1;
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
//logn
