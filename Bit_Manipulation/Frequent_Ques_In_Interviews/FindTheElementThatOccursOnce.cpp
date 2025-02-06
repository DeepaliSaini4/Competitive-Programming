/*
Question 1 Given an array where every element occurs three times, except one element which occurs only once. Find the element that occurs once.

Example:
{23, 5, 23, 4, 23, 4, 5, 3, 5, 4} => 3
{15, 12, 15, 9, 15, 9, 9} => 12
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
    //input
    for(int i=0;i<=30;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(arr[j] &(1<<i)){
                cnt++;
            }
        }
        if(cnt%3){
            ans|=(1<<i);
        }
    }
    cout<< ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}
