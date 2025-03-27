/*
Let us see the following equation,

Ax + By = C

Given three positive integers A, B and C.

You have to determine whether there exists at least one solution for some integers value of x and y where x, y may be negative or non-negative integers.
*/
/*
Bezout's identity states that for any two integers a and b, their greatest common divisor (GCD) can be expressed as the smallest positive integer that can be expressed as a linear combination of a and b
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
        int A, B, C;
        cin >> A >> B >> C;
        int GCD = __gcd(A,B);
        if(C % GCD == 0) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
