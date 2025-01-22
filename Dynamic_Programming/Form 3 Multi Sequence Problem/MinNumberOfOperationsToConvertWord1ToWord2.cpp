/*
Q -> Description
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character

Input Format
Input contains 2 strings word1 and word2.

Output Format
Output the minimum number of operations required to convert word1 to word2.

Constraints
1≤word1.length,word2.length≤500
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

string s1,s2;
int n1,n2;

int dp[501][501];
int rec(int i,int j){//returns the min number of operations required to convert s1 to s2
    //base case
    if(i==n1 || j==n2){
        if(i<n1){
            return n1-i;
        }
        else if(j<n2){
            return n2-j;
        }
        return 0;
    }
    //cache check
    if(dp[i][j]!=-1) return dp[i][j];
    //compute
    int ans =1e9;
    //transition
    if(s1[i] == s2[j]) ans = min(ans,rec(i+1,j+1));
    else{
        ans = min(ans,1+rec(i,j+1)); //delete
        ans = min(ans,1+rec(i+1,j)); //insert
        ans = min(ans,1+rec(i+1,j+1));//replace
    }
    //save and return
    return dp[i][j] = ans;

}
void solver(){
    cin>>s1>>s2;
    n1=s1.length();
    n2=s2.length();
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<"\n";//returns the nim number of operations to convert s1[i..n1] to s2[j...n2]
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}
