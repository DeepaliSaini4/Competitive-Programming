/*
Description
Given a bracket sequence with ‘?’ at some places, you need to find the number of ways you can replace ‘?’ with ‘(‘ or ‘)’ to form a regular bracket sequence. A bracket sequence is called regular if it is possible to obtain the correct arithmetic expression by inserting characters + and 1 into this sequence.

Input Format
The first line of the input contains one integer t - the number of test cases. Then t test cases follow.


The first and only line of each test case contains a string with characters, ‘(‘, ‘)’ and ‘?’.

Output Format
For each test case, print the number of ways to replace ‘?’ with ‘(‘ or ‘)’ to form a balanced bracket sequence mod 10^9+7.

Constraints
1 ≤ t ≤ 105

1 ≤ n ≤ 103 where n is the length of the string.

It is guaranteed that the sum of n2 over all test cases does not exceed 106.

Sample Input 1
5
(??)
??
()()()
???
??????

Sample Output 1
2
1
1
0
5
*/
#include<bits/stdc++.h>
using namespace std;


#define int long long
const int mod=1e9+7;
string s;
int dp[1001][1001];

int rec(int level, int depth){
    //pruning
    if(depth<0) return 0;
    
    //base case
    if(level == s.size()){
        if(depth==0) return 1;
        return 0;
    }
    
    //cache check
    if(dp[level][depth]!=-1) return dp[level][depth];
    
    //compute
    int ans = 0;
    if(s[level]=='?'){
        ans = (rec(level+1,depth+1)%mod + rec(level+1,depth-1)%mod);
        
    }
    else if(s[level]=='('){
        ans = rec(level+1,depth+1)%mod;
    }
    else if(s[level]==')'){
        ans = rec(level+1,depth-1)%mod;
    }
    
    //save and return
    return dp[level][depth] = ans%mod;
}

void solver(){
    // Initialize dp array with -1 for each test case
    cin>>s;

   for(int i=0;i<=s.size();i++){
    for(int j=0;j<=s.size();j++){
        dp[i][j] = -1;
    }
   }
    cout<<rec(0,0)<<'\n';
   
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) solver();
    return 0;
}
// DEBUG-Dont use memset under strong constraints
//      -when declaring 1e9+7 using #define by default its type is double so instead use int mod = 1e9+7;
