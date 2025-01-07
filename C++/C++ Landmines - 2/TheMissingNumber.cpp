/*
You are given an array A. One random element is removed from A to form array B and one random element is removed from B to form array C. 
You have to find the missing element in B and the missing element in C.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solver(){
    int n;
    cin>>n;

    int sum_a=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        sum_a+=a;
    }

    int sum_b=0;
    for(int i=0;i<n-1;i++){
        int b;
        cin>>b;
        sum_b+=b;
    }

    int sum_c=0;
    for(int i=0;i<n-2;i++){
        int c;
        cin>>c;
        sum_c+=c;
    }
    
    cout<<(sum_a-sum_b)<<" "<<(sum_b-sum_c)<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--)

    solver();

    return 0;
}