/*
You are given an array A, where each ith index represents an elevation on that index. The width of each bar is 1. You have to compute how much water it is able to trap 
after raining.
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
        int n;
        cin>>n;

        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];

        vector<int>prefix(n);
        prefix[0] = arr[0];

        vector<int>suffix(n);
        suffix[n-1] = arr[n-1];

        for(int i=1;i<n;i++) prefix[i] = max(prefix[i-1],arr[i]);
        for(int i=n-2;i>=0;i--) suffix[i] = max(suffix[i+1],arr[i]);

        int ans = 0;

        for(int i=1;i<n-1;i++){
            if(arr[i]<= prefix[i-1] && arr[i] <=suffix[i+1]){
                int minheight = min(prefix[i-1],suffix[i+1]);
                ans +=(minheight-arr[i]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
