#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[1010][1010];
int dx[] = {0,1};
int dy[] = {1,0};

int check(int a,int b){
    if(a>=0 && a<n && b>=0 &&b<m)
    return 1;
    return 0;
}

int dp[51][51][51];//dp of n^2m
int rec(int i,int j,int a){//max collection to reach (n-1,m-1,n-1,m-1)
    int b= i+j-a;//b can be retrieved fromt he other states
    cout<<i<<" "<<j<<" "<<a<<" "<<b<<'\n';
        //pruning
        //base case
        if(i==n-1 && j==m-1){
            return arr[i][j];//last celll cost added in the base case
        }
        //cache check
        if(dp[i][j][a]!=-1){
            return dp[i][j][a];
        }
        //transition
        int initial_cost = arr[i][j]+arr[a][b];
        if(a==i && b==j){
            initial_cost = arr[i][j];
        }
        
        int ans = 0;
        for(int k1=0;k1<2;k1++){
            for(int k2=0;k2<2;k2++){
                int ni, nj, na, nb;
                //all four coordinates moves to al new cell
                ni = i+dx[k1];
                nj = j+dy[k1];
                na = a+dx[k2];
                nb = b+dy[k2];
                if(check(ni,nj) && check(na,nb)){
                   ans = max(ans,initial_cost+rec(ni,nj,na));
                }
            }
        }
        //save and return
        return dp[i][j][a] = ans;
        
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout<<rec(0,0,0)<<'\n';
    return 0;
}
