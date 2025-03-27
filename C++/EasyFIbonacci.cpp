/*
Given a number N. Print the first N numbers of the Fibonacci sequence.
Note: In order to create the Fibonacci sequence, use the following function:
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin>>n;

    if(n==1) cout<<"0";
    else{
        int a = 0;
        int b = 1;
        cout<< a << " " <<b <<" ";
        for(int i=3;i<=n;i++){
            cout<< a+b <<" ";
            int t = b;
            b = a+b;
            a = t;
        }
    }

    return 0;
}
