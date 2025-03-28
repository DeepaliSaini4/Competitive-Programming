/*
Given an array of N integers, find the number of subarrays with a sum less than equal to K.
*/
//parallelism -->Number of subarrays formed from a given element as a start element == length of the largest subarray starting from that element.
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

        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];

        int tail = 0;
        int head = -1;

        int sum = 0;
        int ans = 0;

        while(tail<n){
            while(head+1<n && sum+arr[head+1]<=k){
                head++;
                sum+=arr[head];
            }
            ans += (head - tail + 1);
            if(tail>head){
                tail++;
                head = tail-1;
            }else{
                sum-=arr[tail];
                tail++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
