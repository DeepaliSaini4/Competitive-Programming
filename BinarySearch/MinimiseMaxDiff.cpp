/*
You are given N distinct points on the number line in a sorted array A. 
You can place at most K more points on the line (integer coordinates only).
You have to make the maximum separation between any two consecutive points in the final configuration as minimum as possible. 
Output this minimal value.
Note: You can place the points anywhere you like, but you cannot place more than one point at the same position on the line.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
int n,k;
vector<int>arr;

bool check(int x){
    int needed = 0;
    for(int i=1;i<n;i++){
        needed+= (((arr[i] - arr[i - 1]) + x - 1) / x) - 1;
    }
    return needed<=k;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int t;
    cin>>t;
    
    while(t--){
        
        cin>>n>>k;
        arr.resize(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        
       sort(arr.begin(), arr.end()); 
        
        int lo = 1;
        int hi = 0;
        for(int i=1;i<n;i++){
            hi = max(hi,arr[i]-arr[i-1]);//maximum gap between the elements
        }
        int ans = -1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(check(mid)){
                ans = mid;
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
            cout<<ans<<'\n';
    }
    return 0;
}
