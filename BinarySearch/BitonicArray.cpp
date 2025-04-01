/*
Given a bitonic array A consisting of N integers and an integer Q. In each query, you will be given an integer K,
find the positions of K in A. Integer K exists in A.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 
int n;
vector<int>arr;

bool check(int i){
    if (i == 0) return true; 
   if(arr[i]>arr[i-1])return 1;
   else return 0;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--){

        int n,q;
        cin>>n>>q;

        arr.resize(n);
        for(int i=0;i<n;i++)cin>>arr[i];

        int lo = 1; 
        int hi = n - 1; 
        int ans = 0;
        while(lo<=hi){
            int mid = (hi + lo)/2;
            if(check(mid)){
                ans = mid;
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }

        while(q--){
            int k;
            cin>>k;

            vector<int>final;
            lo = 0;
            hi = ans - 1;
            while(lo<=hi){
                int mid = (lo + hi)/2;
                if(arr[mid]==k){
                    final.push_back(mid+1);
                    break;
                }else if(arr[mid]>k){
                    hi= mid - 1;
                }else{
                    lo = mid + 1;
                }
            }
        
        lo = ans;
        hi = n-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(arr[mid]==k){
                final.push_back(mid+1);
                break;
            }else if(arr[mid]>k){
                lo = mid+1;
            }else{
                hi = mid -1;
            }
        }
        
        for(auto v:final){
            cout<<v<<" ";
        }
        cout<<"\n";
        }
    }
    return 0;
}
