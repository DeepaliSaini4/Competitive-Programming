/*
  Q-> Description
You may recall that an array arr is a mountain array if and only if:arr.length≥3
There exists some index 
i (0-indexed) with 0<i<arr.length−1 such that: arr[0]<arr[1]<...<arr[i−1]<arr[i] ........arr[i]>arr[i+1]>...>arr[arr.length−1]
Given an integer array​​​, output the minimum number of elements to remove to make arr​​​ a mountain array. If mountain array is not possible, output -1.

Input Format
First-line contains 
T - the number of test cases.
First-line of each test case contains 
n - the length of the array arr.
Second-line of each test case contains 
n elements of array arr.

Output Format
For each test case, output the minimum number of elements to remove to make arr​​​ a mountain array.
If mountain array is not possible, output -1.

Constraints
1≤T≤1000
1≤n≤10 
1≤arr[i]≤10 ^6
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
int n;
vector<int>arr;
vector<int>lis;
vector<int>lds;

void solver(){
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //lis
    int lis_dp[n];//stores length of the lis ending at index i
    for(int i=0;i<n;i++){
        if(lis.empty() || lis.back()<arr[i]){
            lis.push_back(arr[i]);
        }
        else{
            auto it = lower_bound(lis.begin(),lis.end(),arr[i]);
            *it = arr[i];
        }
        lis_dp[i] = lis.size();
    }
    //lds
    int lds_dp[n];//stores the index of the lds ending at index i
    for(int i=n-1;i>0;i--){
        if(lds.empty() || lds.back()<arr[i]){
            lds.push_back(arr[i]);
        }
        else{
            auto it = lower_bound(lds.begin(),lds.end(),arr[i]);
            *it = arr[i];
        }
        lds_dp[i] = lds.size();
    }
    //longest_mountin sequence
    int len = -1;
    for(int i =0 ;i<n;i++){
        if(lis_dp[i]>=2 && lds_dp[i]>=2){
            len = max(len, lis_dp[i]+lds_dp[i]-1);
        }
    }
    int removals = (len==-1)? -1:(n-len);
    cout<<removals<<'\n';
    arr.clear();
    lis.clear();
    lds.clear();
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) solver();
    return 0;
}
