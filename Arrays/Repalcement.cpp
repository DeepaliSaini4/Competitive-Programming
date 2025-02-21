/*
Description
Given a number Nand an array A of N numbers. You need to replace every positive number in the array with 1, and every negative number with 2. Zeroes remain unchanged.

Print the array after the replacements.

Input Format
The first line contains an integer T, the number of test cases.
For each test case:The first line contains an integer N, the number of elements.The second line contains N space-separated integers representing the array A.

Output Format
Print the array after the replacements, with its values separated by spaces.
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
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            if(a>0) cout<<1<<" ";
            else if(a<0) cout<<2<<" ";
            else cout<<a<<" ";
        }
        cout<<"\n";
    }
}
