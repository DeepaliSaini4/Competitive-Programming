/*
Description
Given two strings. The task is to find the length of the longest common substring.

Input Format
First-line contains T - the number of test cases.Each test case contains two strings s1 and s2 in a single line.

Output Format
For each test case, output the length of the longest common substring of the two strings, in a new line.

Constraints
1≤T≤100
1≤∣s1∣≤1000
1≤∣s2∣≤1000
s1 and s2 contains small letters only.

Sample Input 1
3
abc abc
algozenith algo
algo zenith

Sample Output 1
3
4
0
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 
string s1,s2;
int n1,n2;

int dp[1001][1001];
int rec(int i,int j){//returns the length of the longest substring starting from index i in s1 and index j from s2
    //pruning - out of bound indexes
    if(i>=n1 || j>=n2) return -1e9;
    //base case
    if(i==n1-1 || j==n2-1) return s1[i]==s2[j];
    //cache check
    if(dp[i][j]!=-1) return dp[i][j];
    //compute
    int ans = 0;
    if(s1[i]==s2[j]) ans = max(ans,1+rec(i+1,j+1));
    else ans = 0;
    //save and return
    return dp[i][j] = ans;
}

void solver(){
    cin>>s1>>s2;
    n1=s1.length();
    n2=s2.length();
    int max_len=0;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
         max_len = max(max_len,rec(i,j));
        }
    }
    cout<<max_len<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    solver();
    return 0;
}
