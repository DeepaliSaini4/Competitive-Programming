// Print the subarrays whose sum is equal to k
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    
    int p[n];
    //taking input and building prefix sum at same time
    for(int i=0;i<n;i++){
        cin>>p[i];
        if(i>0) p[i] += p[i-1];
    }
    long long sum = 0;
    map<int,vector<int>>mp;
    mp[0].push_back(-1);
    for(int i=0;i<n;i++){
        sum += mp[p[i]-x].size();
        for(auto v:mp[p[i] - x]){
            cout<<v+1<<","<<i<<"\n";
        }
        mp[p[i]].push_back(i);
    }
    cout<<sum<<'\n';
}
