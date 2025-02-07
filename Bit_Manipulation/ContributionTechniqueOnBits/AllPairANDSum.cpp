/*
Problem Statement: You are given array a containing n elements. You have to find ΣΣ( a[i] & a[j] ).
n<= 10^5
*/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    //taking input
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //declaring ans
    long long ans = 0;
    for(int j=0;j<31;j++){//jth bit- 0th,1st.........30th bit
        long long cnt[2]; //array to store cnt of 0s and 1s
        cnt[0]=cnt[1]=0; //initially setting it to zero
        for(int i=0;i<n;i++){//ith element of array
            cnt[(arr[i]>>j)&1]++; 
        }
        long long numPairs = cnt[1]*(cnt[1]-1)/2;//xor will be the accumulation of all 0 and 1 pairs
        ans += numPairs*(1LL<<j);
    }
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
//tc = O(31*n)
