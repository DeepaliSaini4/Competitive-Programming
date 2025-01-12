/*
Description
Given an integer array arr, output the number of longest increasing subsequences.
Notice that the sequence has to be strictly increasing.

Input Format
First line contains 
T - the number of test cases.
First line of each test case contains 
n - the length of the array arr.
Second line of each test case contains array arr.

Output Format
For each test case, output the number of longest increasing subsequences in a newline modulo 1000000007.

Constraints
1≤T≤100
1≤n≤1000
−10^6≤arr[i]≤10^6

Sample Input 1
4
5
1 2 2 3 6
5
1 3 5 4 7
6
1 1 1 1 1 1
4
3 1 1 2

Sample Output 1
2
2
6
2
*/

#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
int n;
vector<int>arr;
int dp[1000100];//length of the best lis formed uptil the level th index
int cnt[1000100];//count of the best lis formed uptil the given index

int rec(int level){//Best LIS ending at the current index level in [1...level]
    //pruning
    //base case
    if(level == 0){
        cnt[level] = 1;
        return 1;
    }
    //cache check
    if(dp[level]!=-1){
        return dp[level];
    }
    //compute
    int ans = 1;
    for(int prev = 0; prev<level; prev++){
        if(arr[prev] <arr[level]){
            ans = max(ans,1+rec(prev));
        }
    }
    cnt[level] = 0;
    for(int prev=0;prev<level;prev++){
        if(arr[prev]<arr[level] && rec(prev) == ans -1){
            cnt[level] = (cnt[level]%mod + cnt[prev]%mod) %mod;

        }
    }
    if(ans == 1){
        cnt[level] = 1;
    }

    //save and return
    return (dp[level] = ans);

}

void solver(){
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    memset(cnt,0,sizeof(cnt));

    int best_len = 0;
    int cnt_lis = 0;

    //traverse from right to left to get the all possible LIS
    for(int i=n-1;i>=0;i--){
        int len = rec(i);
        if(best_len <len){
            best_len = len;
            cnt_lis=(cnt[i]%mod);
         }
         else if(best_len == len){
            cnt_lis = (cnt_lis%mod + cnt[i]%mod)%mod;
         }
    }
    cout<<((cnt_lis%mod)+mod)%mod<<'\n';

    arr.clear();
 
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) solver();
    return 0;
}
//TC = O(n^2)
