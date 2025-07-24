#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod =1e9+7;
int factorial(int n){
    int ans=1;
    for(int i=1;i<=n;i++){
        ans= (ans*i) % mod;
    }
    return ans;
}
signed main(){
    cout<<factorial(1e6)<<'\n';
    return 0;
    
}
