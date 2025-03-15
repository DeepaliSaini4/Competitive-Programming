/*
Q ->N intervals each interval is given with 3 different values Li, Ri, Xi need to find the sum of k active Xis for a 
given Yi in querries such that k<=10;
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

using event = pair<pair<int,int>,pair<int,int>>;//each event has 4 values
#define F first
#define S second

/*
inclusivity and exclusivity of end points is decided by this mapping
here both the start and end points are included 
    0 -> start
    1 -> Query
    2 -> end

    here both the start and end points are exclusive
    0 -> end
    1 -> Query
    2 -> start
*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    vector<event>events;
    
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        int l,r,x;
        cin>>l>>r>>x;
        events.push_back({{l,0},{x,i}});
        events.push_back({{r,2},{x,i}});
    }
    
    int q;
    cin>>q;
    
    for(int i=0;i<q;i++){
        int y,k;
        cin>>y>>k;
        events.push_back({{y,1},{k,i}});
    }
    
    sort(events.begin(),events.end());
    int ans[q];
    
    multiset<int> mt;
    for(auto v:events){
        if(v.F.S==0){
            //begining of an interval 
            mt.insert(v.S.F);
        }else if(v.F.S==2){
            //end of an interval
            mt.erase(mt.find(v.S.F));
        }else{
            //query interval
            cout<<"Solving Query no. "<<v.S.S<<endl;
            
            int curr_ans = 0;
            int cnt =0;
            for(auto it = mt.rbegin();it!=mt.rend();it++){
                curr_ans += *it;
                cnt++;
                if(cnt==v.S.F) break;
            }
            ans[v.S.S] = curr_ans;
            
            
        }
    }
    for(int i=0;i<q;i++){
        cout<<"Query "<<i<<":"<<ans[i]<<'\n';
    }
    return 0;
}
//TC = O((N+q)*(log(N+q))+N*log(N+q)+q*k)
