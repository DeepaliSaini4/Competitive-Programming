/*
Q -> Create a high performance team of N person, K are to be selected for a team 
speed s and efficiency e are given.
need to maximize (sum of efficiencies)*(min(speed))
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solver(){
    int n,k;
    cin>>n>>k;
    pair<int,int>arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr,arr+n);
    reverse(arr,arr+n);
    priority_queue<int,vector<int>,greater<int>>pq;
    int top_k_sum =0;
    
    int best_team_score = 0;
    for(int i=0;i<n;i++){
        //insert
        pq.push(arr[i].second);
        top_k_sum += arr[i].second;
        if(pq.size()>k){
            int x = pq.top();
            pq.pop();
            top_k_sum-=x;
        }
        
        if(pq.size()==k){
            best_team_score = max(best_team_score,arr[i].first*top_k_sum);
        }
    }
    cout<<best_team_score<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}
