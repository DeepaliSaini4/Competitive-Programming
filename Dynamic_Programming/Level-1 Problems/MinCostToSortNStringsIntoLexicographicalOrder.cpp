/*
Q -> Description
You are given N strings. You are allowed to reverse the i-th string with a cost c[i]. You have to find the minimum cost needed to sort the strings in lexicographical order.
String A is lexicographically smaller than string B if it is shorter than B (|A| < |B|) and is its prefix, or if none of them is a prefix of the other and at the first position where they differ character in A is smaller than the character in B.

Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains one integer N.
The second line of each test case contains N space-separated integers - the cost.
Each of the next N lines contains a string.

Output Format
For each test case, print the minimum cost needed to sort the strings in lexicographical order. If it is impossible to sort the strings print -1.

Constraints
1≤T≤100
1≤N≤10 

Sample Input 1
3
3
2 6 7
aca
aad
fba
3
5 1 1
pbc
cbe
qbf
2
4 5
baa
aaa

Sample Output 1
6
6
-1
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

int n;
vector<int>cost;
vector<string>s;
vector<string>reverseS;

int dp[100001][3];
int rec(int level,int prev_s){
        //pruning
        //base case
        //Reason: In a minimization problem, returning 1e18 in the base case incorrectly assumes failure by default and contaminates even valid paths through min operations, while returning 0 lets valid paths accumulate their true costs while still catching impossible paths during the lexicographical checks.
        if(level == n)return 0;
        //cache check
        if(dp[level][prev_s]!=-1) return dp[level][prev_s];
        //compute
        int ans = 1e18;
        //two choices either reverse the current string or not based on condition
        //for the first string we gotta try both the possibilities
    
        
        string prev = (prev_s==1)?reverseS[level-1]:s[level-1];
        if(prev<=s[level]){
            ans = min(ans,rec(level+1,0));
        }
        if(prev<=reverseS[level]){
            ans = min(ans,rec(level+1,1)+cost[level]);
        }
        //save and return
        return dp[level][prev_s] = ans;
}

void solver(){
    //taking input
    cin>>n;
    cost.resize(n);
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    s.resize(n);
    reverseS.resize(n); //stores the reverse of each string
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        reverseS[i] = s[i];
        reverse(reverseS[i].begin(), reverseS[i].end());
    }

    memset(dp,-1,sizeof(dp));//initializes memory block of dp with the value -1
 // returns the min cost to reverse the string in order to make them lexicographically ordered from level [o...n-1] provided whether or not the rpevious string 
  //was reversed or not
    int ans = 1e18;
    ans = min(ans, rec(1, 0));  
    ans = min(ans, rec(1, 1) + cost[0]);    
    if(ans==1e18) cout<<"-1\n";
    else cout<<ans<<"\n";
    //clear globals
    s.clear();
    cost.clear();
    reverseS.clear();

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
