/*
Question 4 Find the XOR of numbers from 1 to n.

Example:

12 => 12
15 => 0
*/
// Every bit at a position cycles at the frequency of its position for the consecutive numbers ahead!
// A periodic property holds in xoring numbers uptil N
#include<bits/stdc++.h>
using namespace std;

int xor_finder(){
    int n;
    cin>>n;
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
    cout<<xor_finder()<<'\n';
    return 0;
}

