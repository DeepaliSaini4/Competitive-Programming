/*
You are given an array A of size N. You need to find the number of pairs (i, j) , i != j, such that A[i]+A[j] ≤ X.

Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains two space-separated integers N X.

The second line of each test case contains N space-separated integers.
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
        int n,x;
        cin>>n>>x;

        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];   

        sort(arr,arr+n);
        
        int sum = 0;
        for(int i=0;i<n;i++){
            int j = upper_bound(arr,arr+n,x-arr[i])-arr;
            if(arr[i]<= x - arr[i])j--;
            sum += j;
        }
        cout<<sum<<'\n';
    }
    return 0;
}
