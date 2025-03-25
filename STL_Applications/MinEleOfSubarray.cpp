/*
Problem: Given an array of integers arr and an integer k, write a function to print the minimum element of each k-size subarray.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solver(){
    int n,k;
    cin>>n>>k;
    
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    
    multiset<int>ml;
    
    for(int i =0;i<n;i++){
        ml.insert(arr[i]);
        
        if(i>=k) ml.erase(ml.find(arr[i-k]));
        
        if(i>=k-1) 
        cout<<*ml.begin()<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int t;
    cin>>t;
    
    while(t--) solver();
    return 0;
}
//nlogk
