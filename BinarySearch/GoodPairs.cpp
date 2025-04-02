/*
You are given two arrays A and B, both of size N. A pair is called good if i < j and Ai + Aj > Bi + Bj. Find the number of good pairs.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 
int n;
vector<int>a;
vector<int>b;
vector<int>c;


void solver(){

    cin>>n;

    a.resize(n);
    b.resize(n);
    c.resize(n);

    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    for(int i=0;i<n;i++) c[i] = (a[i] - b[i]);

    sort(c.begin(),c.end());

    int cnt = 0;

    for(int i=0;i<n;i++){
        if(c[i]<=0){
            auto it = upper_bound(c.begin(),c.end(),-c[i]);
            if(it != c.end()){
                cnt += (c.end() - it);
            }
        }else{
                 cnt += (n-i-1);
            }
    }
    cout<<cnt<<'\n';
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--) solver();
    return 0;
}
