/*
You are given a convex N-gon. Draw all the diagonals of the convex N-gon. Suppose that no three diagonals pass through the same point.
Into how many parts is the N-gon divided?
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int mod = 1e9+7;

int bin_pow(int a,int b){
    if(!b) return 1;
    if(b%2) return a * bin_pow(a,b-1)%mod;
    else{
        int x = bin_pow(a,b/2);
        return (x*x)%mod;
    }
}

int inverse(int x){
    return bin_pow(x,mod-2)%mod;
}

void solver(){
    int n;
    cin>>n;
    int nc4 = ((((n*(n-1))%mod * (n-2))%mod * (n-3))%mod * inverse(24))%mod;
    int nc2 = (((n*(n-1))%mod * inverse(2))%mod)-n;
    cout<< ((((nc2 + nc4 + 1)%mod)+mod)%mod)<<'\n';

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;
    while(t--) solver();
    return 0;
}
