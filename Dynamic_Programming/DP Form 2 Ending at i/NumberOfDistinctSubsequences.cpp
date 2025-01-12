/*
Given a string, count the number of distinct subsequences of it (including empty subsequence).
For the uninformed, a subsequence of a string is a new string which is formed from the original string by deleting some of the characters without disturbing the relative positions of the remaining characters.
For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.

Input
First line of input contains an integer T which is equal to the number of test cases. You are required to process all test cases. Each of next T lines contains a string s.

Output
Output consists of T lines. Ith line in the output corresponds to the number of distinct subsequences of ith input string. Since, this number could be very large, you need to output ans%1000000007 where ans is the number of distinct subsequences.

Example
Input:
3
AAA
ABCDEFG
CODECRAFT

Output:
4
128
496

Constraints and Limits
T ≤ 100, length(S) ≤ 100000
All input strings shall contain only uppercase letters.
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long

void solver(){
    int n;
    string s;
    cin>>s;
    n=s.length();
    
    int prefix[n+1];
    int last[26];
    int dp[n+1];
    memset(last,-1,sizeof(last));
    
    dp[0] = 1;//unique subseq ending at i-1 of string
    prefix[0] = 1;// sum of dp[0......i].
    for(int i = 1;i<=n;i++){
        //add after all character
        dp[i] = prefix[i-1];
        if(last[s[i-1]-'a']!=-1){
            //remove all duplicates
           int index = last[s[i-1]-'a'];
            dp[i] -=prefix[index];
        }
        //update this as the last index where this char is present
        last[s[i-1]-'a'] = i-1; 
        //keep building the prefix sum
        prefix[i] = prefix[i-1] + dp[i];
    }
    //-1 to remove the "" at the dp[0].
    cout<<prefix[n]-1<<'\n';
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
