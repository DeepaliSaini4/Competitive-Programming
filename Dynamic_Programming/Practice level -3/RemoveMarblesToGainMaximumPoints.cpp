/*
Description
You are given N marbles in different colours. You have to remove marbles till there are no marbles left.
Each time you can choose continuous marbles with the same color, remove them and get k*k points (where ‘k’ is the length of the continuous marbles removed). 
Find the maximum points you can get.

Input Format
The first line contains one integer N - the length of the array.
The second line contains N space-separated integers - the colours of the marbles.

Output Format
Print the maximum points you can get in a new line.

Constraints
1 ≤ N ≤ 100
0 ≤ Ai ≤ 100

Sample Input 1
4
2 1 3 2

Sample Output 1
6
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 
vector<int>color;

int dp[101][101][101];
int rec(int l,int r,int x){
    //pruning
    if(l>r) return 0;
    //base case
    if(l==r) return (x+1)*(x+1);
    //cache check
    if(dp[l][r][x]!=-1) return dp[l][r][x];
    //transition
    int points=-1e9;
    points = max(points,rec(l+1,r,0)+(x+1)*(x+1));
    //grouping marbles
    for(int mid= l+1;mid<=r;mid++){
        if(color[l]==color[mid])
        points = max(points,rec(l+1,mid-1,0)+rec(mid,r,x+1));
    }
    //save and return
    return dp[l][r][x] = points;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    color.resize(n);
    for(int i=0;i<n;i++){
        cin>>color[i];
    }
    cout<<rec(0,n-1,0);//returns the maximum points by removing the marbles from 0 to the  n-1 th level such that x marbles are grouped together at the index l
    return 0;
}
