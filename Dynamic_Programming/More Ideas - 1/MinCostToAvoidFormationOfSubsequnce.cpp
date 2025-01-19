/*
Description
You are given a string S with length N. Each character is assigned a cost for removing it. Find the minimum cost for removing characters such that it does not contain any subsequence hard.

Input Format

The first line of the input contains one integer 
T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the length of the array.

The second line of each test case contains a string S.

The third line of each test case contains N space-separated integers - the cost of removing a character.

Output Format
For each test case, print the minimum cost for removing characters such that it does not contain any subsequence ‘hard’.

Constraints
1≤ T ≤ 1000

1≤ N ≤ 10^5

1≤ Ai ≤ 10^9

Sample Input 1
3
4
abcd
1 2 3 4
10
hhhaaarrdd
1 2 3 4 1 2 3 4 2 3
4
hard
2 1 4 6
Sample Output 1
0
5
1
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 
int n;
vector<int>arr;
string s2;
string s1="hard";

int dp[100001][5];
int cost(int level,int state){//returns the min cost to remove the sub sequence hard from the index[level.........n]
    //pruning case
    if(state == 4) return 1e18;
    //base case
    if(level == n) return 0;
    //cache check
    if(dp[level][state]!=-1) return dp[level][state];
    //compute
    int ans = 1e18;
    if(s2[level]==s1[state]){
        //remove the element and add the cost
        ans = cost(level+1,state) + arr[level];
        //dont remove and call for the next state
        ans = min(ans,cost(level + 1,state+1));
    }
    else{//when the character doesnot matches
        ans = min(ans,cost(level+1,state));
    }
    //save and return
    return dp[level][state] = ans;

}

void solver(){

    cin>>n;
    cin>>s2;
    arr.resize(n+1);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<cost(0,0)<<'\n';//returns the min_cost to remove the subsequence hard starting from the index 0;

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) solver();
    return 0;
}
