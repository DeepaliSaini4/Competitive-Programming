/*
Question 8 Suppose f(X,Y) = number of positions in binary representation where bits differ. Given an array of integers, find the sum of 
f(ai,aj) for every possible i and j in range 1 to n. Find answer modulo 10^9+7.

Example:
{2, 3, 7, 6, 4} => 32
{1,5,12,7,14,16} => 76

*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
int mod = 1e9+7;

signed main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = 0;
    for(int i=0;i<31;i++){
        int cnt1=0,cnt2=0;
        for(int j=0;j<n;j++){
            cnt1+=((arr[j]&(1<<i))>0);
        }
        cnt2=n-cnt1;
        cnt1=cnt1%mod;
        cnt2=cnt2%mod;
        ans=( (ans%mod) + cnt1*cnt2)%mod;
    }
    cout<<(ans+ans)%mod<<'\n';
    return 0;
}
