//You are given an integer N. You have to find the number of divisors of N.
#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;

        int ans = 0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                if(i*i==n){
                    ans ++;
                }else{
                    ans +=2;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
