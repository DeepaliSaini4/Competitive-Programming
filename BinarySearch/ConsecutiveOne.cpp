/*
Given a binary array of length N. The score of an array is the length of the longest continuous subsegment consisting of only 1.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

int n,k;
int arr[100100];
int p[100100];

int numzero(int l,int r){
    return (r-l+1)-(p[r]-(l>0?p[l-1]:0));
}

bool check(int st, int x){
    return numzero(st,x) <= k;
}

void solver(){
    
    cin>>n>>k;
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
        p[i] = arr[i];
        if(i)p[i] +=p[i-1];
    }
    int score = 0;
    for(int st = 0;st<n;st++){
        int lo = st;
        int hi = n-1;
        int ans = st - 1;
        while(lo<=hi){
            int mid = (hi+lo)/2;
            if(check(st,mid)){
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid -1;
            }
        }
        score = max(score,(ans - st +1));
    }
    cout<<score<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int t;
    cin>>t;
    
    while(t--){
        solver();
    }
    
    return 0;
}

//nlogn 
