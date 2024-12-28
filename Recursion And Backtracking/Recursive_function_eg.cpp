#include<bits/stdc++.h>
using namespace std;

int ans = 0;
int f(int x){
   if(x<=3) return x;
   ans += f(x-2);
   return f(x-1)+f(x-3);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<f(10)<<'\n';
    cout<<ans<<'\n';
  
    return 0;
}