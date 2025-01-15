#include<bits/stdc++.h>
using namespace std;

#define int long long 
int n;
int x[101],y[101];
int dp[10001][10001];
int back[101][101]; // Stores optimal still points to minimize the cost of matrix multiplication

int rec(int l,int r){
    //check
    if(l>r) return 0;
    //base case
    if(l==r) return 0;
    //cache check
    if(dp[l][r]!= -1) return dp[l][r];
    //compute
    int ans = 1e9;
    for(int mid = l;mid<r;mid++){
        if((rec(l,mid)+rec(mid+1,r)+x[l]*y[mid]*y[r])<ans)
        ans = min(ans, rec(l,mid)+rec(mid+1,r)+x[l]*y[mid]*y[r]);//update the ans
        //any updation must be stored
        back[l][r] = mid;
    }
    //save and check
    return dp[l][r] = ans;
}

// to keep track of grouping
int opb[101];//counts how many opening brackets are needed before matrix i in the optimal multiplication sequence
int clb[101];//counts how many closing brackets are needed after the trix i in the optimal multiplication sequence

void generate(int l,int r){
    if(l==r)return;
    opb[l]++;
    clb[r]++;
    int mid = back[l][r];
    generate(l,mid);
    generate(mid+1,r);
}

void solver(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    
    memset(dp,-1,sizeof(dp));
    cout<<rec(1,n)<<'\n';
    generate(1,n);
    for(int i=1;i<=n;i++){
        for(int x=0;x<opb[i];x++){
            cout<<"(";
        }
        cout<<" "<<i<<" ";
        for(int x=0;x<clb[i];x++){
            cout<<")";
        }
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;

}