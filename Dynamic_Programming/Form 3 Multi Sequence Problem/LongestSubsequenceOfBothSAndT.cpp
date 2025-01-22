/*
Problem Statement
You are given strings s and t. Find one longest string that is a subsequence of both s and t.

Notes
A subsequence of a string x is the string obtained by removing zero or more characters from 
x and concatenating the remaining characters without changing the order.

Constraints
s and t are strings consisting of lowercase English letters.
1≤∣s∣,∣t∣≤3000

Input
Input is given from Standard Input in the following format:
s
t
Output
Print one longest string that is a subsequence of both s and t. If there are multiple such strings, any of them will be accepted.

Sample Input 1
axyb
abyxb
Sample Output 1
axb
The answer is axb or ayb; either will be accepted.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 
string s,t;
int n,m;
int back[3030][3030];
/* 0 ->diagonal
   1 ->down
   2 ->right
*/
int dp[3030][3030];
int rec(int i,int j){//returns the longest subsequence starting from i in s1 and j in s2
    //pruning
    //base case
    if(i>=n || j>=m) return 0;
    //cache check
    if(dp[i][j]!=-1) return dp[i][j];
    //compute
    int ans = 0;
    if(s[i]==t[j]) {
       if(ans < 1 + rec(i + 1, j + 1)) {
            ans = 1 + rec(i + 1, j + 1);
            back[i][j] = 0; // Diagonal move 
       }
    }
    if(ans  < rec(i,j+1)){
        ans =rec(i,j+1);
        back[i][j] = 2; 
    }
    if(ans < rec(i+1, j)) {
        ans = rec(i+1,j);
        back[i][j] = 1;
    }
    //save and return
    return dp[i][j] = ans;
}

void generate(){
    string result ="";
    int i=0;
    int j=0;
    while(i<n && j<m){
        if(back[i][j]==0){
            result += s[i];
            i++;
            j++;
        }
        else if(back[i][j]==1){
            i++;
        }
        else if(back[i][j] == 2){
            j++;
        } else break;
    }
    
    cout<<result;
}
void solver(){
    cin>>s>>t;
    n = s.length();
    m = t.length();
    memset(dp,-1,sizeof(dp));
    memset(back, -1, sizeof(back));
    
    int ans = rec(0,0);//retuns the longest string starting from 
    // index 0 in s1 and index 0 in s2
    generate();
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}
