/*
Question 2 Given an array where every element occurs an even number of times, except one element which occurs an odd number of times. Find the element that occurs an odd number of times.

Example:

{23, 15, 23, 4, 23, 4, 15, 4, 23, 15, 15} => 4
{15, 19, 12, 15, 19, 19, 19} => 12

*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solve(){
    int n;
    cin>>n;
    int arr[n];
    int ans = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        ans ^=arr[i];
    }
    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}
