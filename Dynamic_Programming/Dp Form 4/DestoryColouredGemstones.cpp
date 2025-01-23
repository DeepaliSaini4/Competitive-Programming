/*
Q -> Description
You are given an array of colored gemstones. In one second, you can remove exactly one continuous substring of colored gemstones that is a palindrome. You have to find the minimum number of seconds needed to destroy all the gemstones.

Input Format
The first line of the input contains one integer 
T - the number of test cases. Then T test cases follow.


The first line of each test case contains one integer N - the length of the array.


The second line of each test case contains N space-separated integers.

Output Format
For each test case, print the minimum number of seconds needed to destroy all the gemstones.

Constraints
1≤ T ≤ 200

1≤ N ≤ 100

1≤ Ai ≤ N
Sample Input 1
3
4
1 3 3 1
3
2 4 3
11
1 3 2 3 2 4 3 3 4 3 1

Sample Output 1
1
3
2
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

int n;
vector<int>gems;

int dp[101][101];
int rec(int l,int r){ //returns the minimum number of seconds needed to destroy all the gemostones between [l....r]
        //pruning
        if(l>=n || r<0 || l>r) return 0;
        //base case
        if(l == r) return 1;
        //cache check
        if(dp[l][r]!=-1) return dp[l][r];
        //compute
        int secs = 1e9;
        //way-1: delete alone
        secs = min(secs, 1 + rec(l+1,r));
        //way-2: delete with neighbour
        if(l+1<n && gems[l]==gems[l+1])
        secs = min(secs, 1 + rec(l+2,r));
        //way-3 Delete as a start of some palindrome
        for(int i=l+2;i<=r;i++){
            if(gems[l]==gems[i]){
                secs = min(secs ,rec(l+1,i-1)+rec(i+1,r));
            }
        }
        //save and return
        return dp[l][r] = secs;
}

void solver(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        gems.push_back(a);
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n-1)<<'\n';
    n=0;
    gems.clear();
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) solver();
    return 0;
}
