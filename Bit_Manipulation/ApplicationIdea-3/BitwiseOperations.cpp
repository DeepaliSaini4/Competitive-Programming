/*
Description
Given an array of N positive integers. You can perform this operation any number of times, choose two indices x and y. If array[x] = a and array[y] = b, then after the operation

1. array[x] = a OR b, array[y] = a AND b.

Perform the operations optimally such that ∑array[i]*array[i] for all 1<=i<=n is maximum. Print the largest sum of squares you can get after performing the operations greater than equal to zero times.

Input Format
The first line of the input contains a single integer T denoting the number of test cases, (1<=T<=100).

The first line of each test case contains a single integer N, (2<=N<=100000).

The second line contains N space-separated integers A1,A2,…,AN, (1<=Ai<=10^6).

Sum of N over all test cases does not exceed 10^6.

Output Format
For each test case output a single integer representing the largest possible sum of squares that can be achieved after several (possibly zero) operations.

Sample Input 
5
2
2 5
3
1 2 3
5
1 2 3 4 5
1
1234
10
2 5 234 3454 3423 34545 65433 654345 9876 76567

Sample Output 1
49
18
99
1522756
448865876262
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin>>n;
    int arr[n];
    int cnt[21];//stores the number of ones at the jth position of all numbers
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<=20;j++){
            if(arr[i]&(1<<j)){
                cnt[j]++;
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        int largepos = 0;
        for(int j=0;j<=20;j++){
            if(cnt[j]){
                largepos |=(1<<j);
                cnt[j]--;
            }
        }
        ans +=largepos*largepos;
    }
    cout<<ans<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
// TC = O(n*log(maxAi))

