/*
You are given the digits of a positive number N. Find the product of its digits. Since the product can be large, print it modulo 109 + 7.
It is guaranteed that the number begins with a non-zero digit
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

int mod = 1e9 +7;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int pro = 1;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            pro = (pro * x)%mod;
        }
        cout<< pro <<'\n';
    }
    return 0;
}
