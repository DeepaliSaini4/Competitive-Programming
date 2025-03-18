/*
Given 2 numbers N, M and an array A of N numbers. For every number from 1 to M, print how many times this number appears in this array.
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
        int n,m;
        cin>>n>>m;

        int arr[n];

        for(int i=0;i<n;i++) cin>>arr[i];

        int freq[(int)(1e5+1)]={0};

        for(int i=0;i<n;i++)freq[arr[i]]++;

        for(int i=1;i<=m;i++) cout<<freq[i]<<'\n';
    }
    return 0;
}
