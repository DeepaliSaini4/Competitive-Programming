/*
You are given an array A of size N. You have to answer the following queries:

1 x - Find the smallest element ≥ x.
2 x - Find the smallest element > x.
3 x - Find the number of elements ≤ x.
4 x - Find the number of elements < x.
If the answer does not exist, print -1.
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
        int n,q;
        cin>>n>>q;

        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];

        sort(arr,arr+n);

        while(q--){
            int t,x;
            cin>>t>>x;
 
            if(t == 1){
                int i = lower_bound(arr,arr+n,x) - arr;
                if (i==n) cout<<"-1 ";
                else cout<< arr[i] <<" ";
            } else if(t ==2){
                int i = upper_bound(arr,arr+n,x)-arr;
                if(i==n) cout<<"-1 ";
                else cout<<arr[i]<<" ";
            }else if(t==3){
                 cout << upper_bound(arr,arr+n,x)-arr<<" ";
            }else{
                cout << lower_bound(arr,arr+n,x)-arr<<" ";
            } 
        }
        cout<<'\n';
    }
    return 0;
}
