/*
Given an array of N integers and Q queries. In each query two integers L, R is given, you have to find (A[L] + A[L+1] + A[L+2] + A[L+3]...A[R]) % 10^9+7.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int mod = 1e9 + 7;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int N, Q;
    cin>>N>>Q;

    int arr[N+1];
    for(int i=1;i<N+1;i++) cin>>arr[i];

    int pre[N+1];
    pre[0] = 0;
    for(int i=1;i<=N;i++){
        pre[i] = ((arr[i] + pre[i-1])+mod)%mod;
    }

    while(Q--){
        int L, R;
        cin >> L >> R;
        cout<<((pre[R] - pre[L-1])+mod)%mod<<'\n';

    }
    return 0;
}
