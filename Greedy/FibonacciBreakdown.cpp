/*
Description
Given a number k, find the minimum number of fibonacci numbers whose sum is equal to k. You can use any of the fibonacci numbers any number of times.
 
Fibonacci Numbers:
F(1) = 1
F(2) = 1
F(n) = F(n-1) + F(n-2) : for n>=3

Input Format
First line of input contains T, number of test cases.The only line of each test case contains an integer k.

Output Format
For each test case output one integer: The minimum number of fibonacci numbers needed.

Constraints
T ≤ 100
1 ≤ k ≤ 109

Sample Input 1
1
7

Sample Output 1
2
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 
int fib[50];

void solver(){

    int k;
    cin>>k;

    int index = 49, fib_nu =0;

    while(k>0){

        if(k>=fib[index]){
            k-=fib[index];
            fib_nu++;
        }
        index--;
    }
    cout<<fib_nu<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //There are less than 50 Fibonacci numbers upto 10^9.
    //precomputing all fibs
    fib[0] = fib[1] = 1;
    for(int i=2;i<50;i++) fib[i] = fib[i-1]+fib[i-2];

    int t;
    cin>>t;
    while(t--) solver();
    return 0;
}
