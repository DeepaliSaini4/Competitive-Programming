#include <bits/stdc++.h>
using namespace std;

int maxprofit(int w,vector<int>&we,vector<int>&pro){
    vector<pair<int,int>>v;
    for(int i=0;i<we.size();i++){
        v.push_back({(pro[i]/we[i]),i});
    }
    sort(v.begin(),v.end(),[](pair<int,int>&a,pair<int,int>&b){
        if(a.first==b.first) return a.second<b.second;
      return  a.first>b.first;
    });
    int accu = 0;
    int wacu = 0;
    for(int i=0;i<v.size();i++){
        accu += pro[v[i].second];
        if(wacu + we[v[i].second] > w){
            // add a fractional part
            int rem = w - wacu;
            accu+= (v[i].first)*rem;
            break;
        }
        wacu += we[v[i].second];
    }
    return accu;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int w = 50;
    vector<int> weights = {20,10,30};
    vector<int>profits = {100,60,120};
    cout<<maxprofit(w,weights,profits);
    return 0;
}
