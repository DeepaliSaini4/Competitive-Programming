/*
You are given an integer N. You have to tell whether the number is a perfect square/cube according to the given query. Do not use inbuilt sqrt() and cube() function. 
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int q,n;
        cin>>q>>n;
        if(q==1){
            bool is_perf_sq = false;
            for(int i=1;i*i<=n;i++){
                if(i*i == n){
                is_perf_sq = true;
                break;
                }
            }
        if(is_perf_sq) cout<<"YES\n";
        else cout<<"NO\n";

        }else{
            bool is_perf_cube = false;
            for(int i=1;i*i*i<=n;i++){
                if(i*i*i == n){
                is_perf_cube = true;
                break;
                } 
            }
            if(is_perf_cube) cout<<"YES"<<'\n';
            else cout<<"NO\n";
        }
        
    }
    return 0;
}
