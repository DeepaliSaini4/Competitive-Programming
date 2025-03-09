/*
Q- create max score by solving problems in such a order that minimum penalty charged on them for the given time t taken to solve each of the problem.
need to sort by decreasing order of penalty/time.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

struct prob{
    int s,d,t;
};

bool comp(prob a,prob b){
    return 1LL * a.d * b.t >1LL * a.t * b.d;
}

void solver(){
    int n;
    cin>>n;
    prob p[n];
    for(int i=0;i<n;i++){
        cin>>p[i].s>>p[i].d>>p[i].t;
    }
    sort(p,p+n,comp);
    int optimal_score = 0;
    int timetaken = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        timetaken +=p[i].t;
      ans += p[i].s - p[i].d*timetaken;
    }
    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}
