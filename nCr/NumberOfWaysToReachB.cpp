/*
You have given a grid of N x M. You are initially at position A(0, 0) and you want to reach B(N, M). 
From the given cell (i, j), we are allowed to move to cells (i + 1, j) and (i, j + 1) only.
Find the number of different ways to reach B from A?
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

const int MAXN = 200010;
int fact[MAXN+1];


//binary exponentiation
int bin_pow(int a,int b){
    if(!b) return 1;
    if(b%2) return (a*bin_pow(a,b-1))%mod;
    else{
        int x = bin_pow(a,b/2);
        return (x*x) % mod;
    }
}
int inverse(int x){
    return bin_pow(x, mod-2);
}

void precompute_fact(){
    fact[0] = 1;
    for(int i=1;i<200001;i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    precompute_fact();

    while(t--){
        int n,m;
        cin>>n>>m;
        
        int num = fact[n+m];
        int deno = (fact[n]*fact[m])%mod;
        int ans = num * inverse(deno);
        cout<<((ans % mod)+mod)%mod<<'\n';
    }
    return 0;
}
