/*
Description
Given a number N. Print all prime numbers between 1 and N inclusive.

A prime number is a number that is greater than 1 and has only two factors which are 1 and itself. In other words, a prime number is divisible only by 
1 and itself. Be careful that 1 is not prime.

The first few prime numbers are 2,3,5,7,11,…

Input Format
Only one line containing a number N.

Output Format
Print all prime numbers between 1 and N (inclusive) separated by a space.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

bool isprime(int x){
    for(int i=2; i*i <= x;i++){
        if(x%i==0) return 0; 
    }
    return 1;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        if(isprime(i))
            cout<<i<<" ";
        }
    return 0;
}
