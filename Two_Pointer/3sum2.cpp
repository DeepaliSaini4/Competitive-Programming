/*
Given an array A of N integers and an integer target, find three integers in A such that the sum is closest to the target (absolute value of (sum-target) is minimum). 
Print the minimum absolute value of (sum-target). You cannot select an index more than one.
All three indexes should be distinct.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solver(){
    int n,target;
    cin>>n>>target;
    
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    
    sort(arr,arr+n);
    int best = arr[0] + arr[1] + arr[2];
    for(int i = 0;i<n;i++){
            int low = 0;
            int high = n-1;
        while(true){
            if(abs(arr[low]+arr[i]+arr[high]-target)<abs(best-target)){
                best = arr[low] + arr[i] + arr[high];
            }
            if(arr[low]+arr[i]+arr[high]>target) high--;
            else low ++;
            if(low==i||high==i) break;
        }
    }
    cout<<abs(best-target)<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--);
    solver();
    
}
