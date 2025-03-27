/*
There are N students and ith student likes all numbers in the range [li ,ri ], both inclusive. A number is good if it is liked by at least K students.
You are even Q queries. Each query consists of two numbers L, R. You have to find how many numbers in the range [L,R] is good.
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


    int pre[N+2];
    pre[0] = 0;
    for(int i=1;i<N+1;i++){
        cin>>pre[i];
        pre[i] = (( pre[i-1]+pre[i])+mod)%mod;
    }

    while(Q--){
        int L, R;
        cin >> L >> R;
        cout<<((pre[R] - pre[L-1])+mod)%mod<<'\n';

    }
    return 0;
}
