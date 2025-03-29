//You are given an array of N integers. Find the length of the longest subarray with distinct elements.

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

        map<int,int>freq;
        int ans = 0;
        int length =0;
        int head = -1, tail = 0;
        while(tail<n){
            while(head+1<n && freq[arr[head+1]]==0){
                head++;
                freq[arr[head]]++;
            }
            length = head - tail +1;
            ans = max(ans , length);
            if(tail>head){
                tail++;
                head = tail-1;
            }else{
                freq[arr[tail]]--;
                tail++;
            }

        }
        cout<<ans<<'\n';
    }
    return 0;
}
