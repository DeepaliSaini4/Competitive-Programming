//Q -> Finf xor from L to R.
#include<bits/stdc++.h>
using namespace std;

int xor_finder(int n){
    int rem = n%4;
    switch(rem){
        case 0: return n;
        case 1: return 1;
        case 2: return n+1;
        case 3: return 0;
    }
    return 1;//dummy return
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int l,r;
    cin>>l>>r;
    cout<<(xor_finder(r)^xor_finder(l-1))<<'\n';
    return 0;
}
