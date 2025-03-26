/*
There are N balls on the X-axis and M balls on the Y-axis. At the time, t=0, each ball on X-axis is thrown parallel to the Y-axis in the positive Y direction. 
Similarly, each ball on Y-axis is thrown parallel to the X-axis in the positive X direction. At any time, if two balls collide, they disappear.
A collision can only happen between the ball thrown from X-axis and the ball thrown from Y-axis. No two balls from X-axis or Y-axis can collide.
A ball can take part in at max one collision. You have to find the total number of collisions. 
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
        int n,m;
        cin>>n>>m;

       map<int,int>mp;
       for(int i=0;i<n;i++){
        int x,u;
        cin>>x>>u;
        mp[x*u]++;
       }

        int ans = 0;

       for(int i=0;i<m;i++){
        int y,v;
        cin>>y>>v;
        if(mp.count(y*v)){
            ans++;
            mp[y*v]--;
            if(mp[y*v]==0) mp.erase(y*v);
        }
    }
    cout<<ans<<'\n';
    }
    return 0;
}
