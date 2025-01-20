/*
Q -> Find k non empty sub arrays that are disjoint and the sum is max
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

int n,k;
int arr[1010];
int p[1010];
int done[1010][1010];
int dp[1010][1010];
int rec(int i,int k){
    if(i<0){
    if(k==0) return 0;
    else return -1e9;
    }
    if(done[i][k]){
        return dp[i][k];
    }
    int ans = rec(i-1,k);
    for(int j=1;j<=i+1;j++){
        ans = max(ans,rec(i-j,k-1)+p[i+1]-p[i-j+1]);
    }
    done[i][k] = 1;
    return dp[i][k] = ans;

}

void solver(){
    
    cin>>n>>k;
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    p[0]=arr[0];
    for(int i=1;i<=n;i++){
        p[i] = arr[i-1] + p[i-1];
    }
    cout<<rec(n-1,k)<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}