/*
Q -> N person visit a hall with entry and exit time given as [Li,Ri] tell the total duration when the number of people in hall in greater than 
or equal to K.
*/
#include<bits/stdc++.h>
using namesapce std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int n;
    cin>>n;
    
    vector<pair<int,int>> events;
    for(int i=0;i<n;i++){
        in tl,r;
        cin>>l>>r;
        events.push_back({l,+1});
        events.push_back({r,-1});
    }
    sort(events.begin(),events.end());
    
    int cnt = 0;
    int ans = 0;
    
    for(int i=0;i<events.size();i++){
        cnt += events[i].second;
        if( i+1 < n && cnt >=k ){
            ans += events[i+1].first - events[i].first;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
