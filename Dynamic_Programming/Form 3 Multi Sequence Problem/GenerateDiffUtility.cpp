#include<bits/stdc++.h>
using namespace std;

#define int long long 

string x,y;
int n,m;

int dp[5050][5050];
int back[5050][5050];
int rec(int l1,int l2){
    //check
    //base
    if(l1==n && l2==m) return 0;
    //cache check
    if(dp[l1][l2]!=-1) return dp[l1][l2];
    //calc
    int ans = 1e9;
    if(l1<n){//-x[l1]
        if(rec(l1+1,l2)+1<ans){
            ans = rec(l1+1,l2)+1;
            back[l1][l2] = 0;
        }
    }
    if(l2<m){//+y[l2]
         if(rec(l1,l2+1)+1<ans){
            ans = rec(l1,l2+1)+1;
            back[l1][l2] = 1;
        }
    }
    if(l1<n && l2<m && x[l1]==y[l2]){//x[l1]
           if(rec(l1+1,l2+1)+1<ans){
            ans = rec(l1+1,l2+1)+1;
            back[l1][l2] = 2;
        }
    
        ans = min(ans,rec(l1+1,l2+1)+1);
    }
    //save ans return
    return dp[l1][l2] = ans;
}

void generate(int l1,int l2){
    if(l1==n && l2==m) return;
    int ch = back[l1][l2];
    if(ch==0){
        cout<<"-"<<x[l1]<<" ";
        generate(l1+1,l2);
    }else if(ch==1){
        cout<<"+"<<y[l2]<<" ";
        generate(l1,l2+1);
    }else{
        cout<<x[l1]<<" ";
        generate(l1+1,l2+1);
        cout<<'\n';
    }
}
void solve(){
    cin>>x>>y;
    n =x.length();
    m =y.length();
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<'\n';
    generate(0,0);
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
