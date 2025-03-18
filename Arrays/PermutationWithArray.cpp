/* Given a number N and two arrays A, B of N numbers. Determine if B is a permutation of A or not.
Note: A permutation is an arrangement of all or part of a set of objects. */
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
        
        int arrA[n];
        int arrB[n];
        for(int i=0;i<n;i++) cin>>arrA[i];
        for(int i=0;i<n;i++) cin>>arrB[i];

        sort(arrA,arrA+n);
        sort(arrB,arrB+n);

        int flag = 1;
        for(int i=0;i<n;i++)if(arrA[i]!=arrB[i])flag = 0;

        if(flag) cout<<"yes"<<'\n';
        else cout<<"no"<<'\n';

    }
    return 0;
}
