/*
Given an integer N and an array A of N distinct numbers. Your task is to find the minimum and 
maximum numbers among them, swap these two numbers, and then print the array after the swap.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int arr[n];
        int mini = -1;
        int maxi = -1;
        int minv = 1e9;
        int maxv = -1e9;

        for(int i=0;i<n;i++) cin>>arr[i];

        for(int i=0;i<n;i++){
            minv = min(minv,arr[i]);
            if(minv==arr[i]) mini = i;
            maxv =max(maxv,arr[i]);
            if(maxv==arr[i]) maxi =i;
        }

        arr[mini] = maxv;
        arr[maxi] = minv;

        for(int i=0;i<n;i++) cout<<arr[i]<<" "; 
        cout<<'\n';
    }
    return 0;
}
