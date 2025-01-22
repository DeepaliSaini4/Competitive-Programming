/*
Q -> Description
Given a string s, find the minimum number of characters that need to be inserted into the string to make it a palindrome.

Input Format
First line contains T - the number of test cases.
First line of each test case contains the string s.

Output Format
For each test case, output the minimum number of characters that need to be inserted into the string to make it a palindrome.

Constraints
1≤T≤100
1≤∣s∣≤1000
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 
string s;
int n;

int dp[1001][1001];
int rec(int l,int r){//returns minimum number of insertions required to make between[l....r] to make the string plaindrome
    //pruning case
    if(l>=n || r<0 || l>r) return 1e9;
    //base case
    if(r==l+1){
        return !(s[l]==s[r]);
    }
    if(l==r) return 0;
    //cache check
    if(dp[l][r]!=-1) return dp[l][r];
    //compute
    int num = 1e9;
    if(s[l]==s[r])
    num = min(num,rec(l+1,r-1));
    else{
        num = min(num,1+rec(l+1,r));//insertion after r
        num = min(num,1+rec(l,r-1));//insertion before l
    }
    //save and return
    return dp[l][r] = num;

}

void solver(){
    cin>>s;
    n = s.length();
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n-1)<<'\n';//returns the min number of insertions between [l...r] to make string palindrome.
    s.clear();
  
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) solver();
    return 0;
}
