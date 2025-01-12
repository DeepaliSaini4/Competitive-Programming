/*
Q --> Description
Given 3 strings s1, s2 and s3, the task is to find the length of the longest common sub-sequence in all three given strings.

Input Format
First-line contains T - the number of test cases.Each test case contains 3 strings in a single line.

Output Format
For each test case, print the length of the longest common subsequence in all the 3 given strings, in a new line.

Constraints
1≤T≤100
1≤∣s1∣≤100
1≤∣s2∣≤100
1≤∣s3∣≤100

Sample Input 1
3
abc abc bbc
algozenith algo algorithm
algo zenith zen

Sample Output 1
2
4
0

*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
int dp[101][101][101];
string a,b,c;

int rec(int i,int j,int k){/*returns the max common subsequence ending at n starting from i,j,k where n is the min out the sizes of all the strings.*/
//base case
if(i==a.length() || j==b.length() || k==c.length())// max length of commom subsequence starting at the indcies equivalent to the size of the strings jis zero
return 0;

//cache check
if(dp[i][j][k]!=-1)
return dp[i][j][k];

//compute
int ans = max({rec(i+1,j,k),rec(i,j+1,k),rec(i,j,k+1)});
if(a[i]==b[j] && c[k]==b[j]) ans= max(ans,1+rec(i+1,j+1,k+1));

//save and return
return dp[i][j][k] = ans;
}

void solver(){ 
    cin>>a>>b>>c;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0,0)<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) solver();
    return 0;
}
