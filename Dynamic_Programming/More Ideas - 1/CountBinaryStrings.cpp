/*
Description
Find the number of binary strings of length n where “0100” is not present as a substring.

Input Format

The first line of the input contains one integer 
t - the number of test cases. Then t test cases follow.

The first and only line of each test case contains an integer n.

Output Format
For each test case, print the number of binary strings of length n where “0100” is not present as a substring mod 10^9+7.

Constraints
1 ≤ t ≤ 106

1 ≤ n ≤ 106 where n is the length of the string.

Sample Input 1
3
3
4
5
Sample Output 1
8
15
28

*/


#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long 

int n;
string t ="0100";

int dp[1000101][5];
int rec(int level,int match){//retuns the number of substring from [level...0] such that no substrings 0100 are formed
        //base case
        if(level ==0) return 1;
        //cache check
        if(dp[level][match]!=-1) return dp[level][match];
        //compute
        int ans = 0;
        if(match == 0){
            ans = rec(level-1, 0)+ rec(level-1,1);
        }
        else if(match == 1){
            ans = rec(level-1, 2)+ rec(level-1,1);
        }
        else if (match == 2){
            ans = rec(level-1, 0)+ rec(level-1,3);
        }
        else if (match == 3){
            ans = rec(level-1, 2);
        }
        //save and return
        return dp[level][match] = (ans%mod);

}

void solver(){
    cin>>n;
    //returns the number of binary strings starting uptil level n  with no 0100 as substrng.
    cout<<rec(n,0)<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    memset(dp,-1,sizeof(dp));


    int t;
    cin>>t;

    while(t--) solver();
    return 0;
}
//Debug:Precompute the ans in 0(n) and then for each test case return the answer in O(1) complexity.
/*
instead of form 1 we use form 2 here so that the call always goes in the backward direction so that the precomputed ans we found mid way 
is accumulated without computing it again
*/
