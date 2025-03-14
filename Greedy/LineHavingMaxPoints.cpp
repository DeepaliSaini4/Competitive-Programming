/*
Q -> N points (Xi,Yi) given find a line that passes through maximum number of points.
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a,int b){
    if(a==0 || b==0) return a+b;
    return gcd(b,a%b);
}

pair<int,int>get_red_frac(int a,int b){
    // a/b -> p/q
    if(a==0 && b==0 ) return make_pair(0,0);
    if(a==0) return make_pair(0,1);
    if(b==0) return make_pair(1,0);
    int neg = 1;
    if(a<0){ neg*=-1; a*=-1;};
    if(b<0){ neg*=-1; b*=-1;};
    int x = gcd(a,b);
    return make_pair(neg*a/x,b/x);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int n;
    cin>>n;
    
    int x[n],y[n];
    
    for(int i=0;i<n;i++) cin>>x[i]>>y[i];
   
    int ans = 0;
    for(int i=0;i<n;i++){
        int same = 0;
        map<pair<int ,int>,int>mp;
        for(int j=0;j<n;j++){
            if(x[j] != x[i] || y[j]!=y[i]){
                mp[get_red_frac(y[i]-y[j],x[i]-x[j])]++;
            }else{
                same++;
            }
        }
        for(auto v:mp){
            ans = max(ans, 1+v.second);
        }
    }
    cout<<ans<<endl;
    return 0;
}
