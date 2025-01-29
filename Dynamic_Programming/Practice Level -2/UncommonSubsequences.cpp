/*
Q ->Description
Given two strings S and T, find length of the shortest subsequence in 
S which is not a subsequence in T. If no such subsequence is possible, return 
−1. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.

Input Format
First-line contains 
t - the number of test cases.
The first line of each test case contains the string S.
The Second-line of each test case contains the string T.

Output Format
For each test case, output the length of the shortest subsequence in S which is not a subsequence in T. If no such subsequence is possible, output −1.

Constraints

1≤t≤100
1≤∣S∣≤1000
1≤∣T∣≤1
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

string s,t;
int n1, n2;
int next_occur[1010][26];  // next_occur[j][ch] stores 1st occurence of char (ch) in t[j...n2-1]

int dp[1010][1010];
int rec(int i, int j) {
    // pruning: no valid subsequence found
    if(i == n1) {
        return 1e18;
    }
    // base case: all subsequences in s[i...n1-1] are valid
    if(j == n2) {
        return 1;
    }
    // cache check 
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    // transition
    int ans = 1e18;
    int first_occur = next_occur[j][s[i] - 'a'];
    if(first_occur == -1) {
        ans = min(ans, 1LL);
    } else {
        ans = min(ans, rec(i+1, j));
        ans = min(ans, 1 + rec(i+1, first_occur+1));
    }
    // save and return
    return (dp[i][j] = ans);
}

void solver(){
    cin >> s >> t;
    n1 = s.size();
    n2 = t.size();
    memset(next_occur, -1, sizeof(next_occur));
    memset(dp, -1, sizeof(dp));

    // Precompute next occurence for each character in t
    for(int j=n2-1; j>=0; j--) {
        for(int ch=0; ch<26; ch++) {
            next_occur[j][ch] = next_occur[j+1][ch];
        }

        next_occur[j][t[j] - 'a'] = j;
    }
    
    // Recurrence Meaning: (Form-3)
    // rec(i, j): length of shortest subsequence in s[i...n1-1],
    // which is not subsequence in t[j...n2-1]
    cout << ((rec(0, 0) == 1e18) ? -1 : rec(0, 0)) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) solver();
    return 0;
} 
