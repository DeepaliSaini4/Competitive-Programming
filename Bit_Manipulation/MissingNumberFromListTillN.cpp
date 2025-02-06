/*
Question 5 One number is missing from the list of integers from 1 to n. Find that missing number.

Example:

{1, 2, 5, 6, 3, 7} => 4
{2, 4, 6, 5, 1} => 3
*/
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
    int n;
    cin>>n;
    int _xor=0;
    for(int i=0;i<n-1;i++){
        int a;
        cin>>a;
        _xor^=a;
    }
    cout<< (_xor^(xor_finder(n)))<<'\n';
    return 0;
}
