/*
Given an array of integers arr and an integer k, write a function to print the minimum element of each k-size subarray.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

struct monotone_deque{
    deque<int>dq;
    void insert(int x){
        while(!dq.empty() && dq.back()>x){
            dq.pop_back();
        }
            dq.push_back(x);
    }
    void erase(int x){
        if(!dq.empty() && dq.front() == x) 
        dq.pop_front();
    }
    int getmin(){
        return dq.front();
    }
};

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int n,k;
    cin>>n>>k;
    
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    
    monotone_deque dq;
    for(int i=0;i<n;i++){
        dq.insert(arr[i]);
        if(i>=k) dq.erase(arr[i-k]);
        if(i>=k-1) cout<<dq.getmin()<<'\n';
    }
    return 0;
}
//o(n)
