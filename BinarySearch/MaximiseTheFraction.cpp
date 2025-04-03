/*
Given two arrays A and B of size N and an integer K. You have to select K indexes i1,i2,i3,i4.... such that 
A[i1]+.................. + A[ik] / /B[i1]+...............+B[ik] is maximum
*/
#include<bits/stdc++.h>
using namespace std;

#define ld long double

int n,k;
vector<int>a;
vector<int>b;


void solver(){
    cin>>n>>k;

    a.resize(n);
    b.resize(n);

    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    ld hi = 1e8;
    ld lo = 0.0;
    ld ans = 0.0;

    while(abs(lo-hi)>1e-9){
        ld mid = (lo+hi)/2.0;
        priority_queue<ld,vector<ld>,greater<ld>>pq;
        for(int i=0;i<n;i++){
            pq.push(a[i]-mid*b[i]);
            if(pq.size()>k)
            pq.pop();
        }
        ld s = 0.0;
        while(pq.size()){
            s+=pq.top();
            pq.pop();
        }
        if(s>=0.0) {
            ans = mid;
            lo = mid;
        }else hi = mid;
    }
        cout<<fixed<<setprecision(6)<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int t;
    cin>>t;

    while(t--) solver();
    return 0;
}
