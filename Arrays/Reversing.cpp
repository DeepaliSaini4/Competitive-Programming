/*
Description
Given a number N and an array A of N numbers. Print the array in a reversed order.

Note: Don't use built-in-functions.

Input Format
The first line contains T, the number of test cases.
For each test case:The first line contains N, the number of elements.
The second line contains N space-separated integers denoting the array.

Output Format
Print the array in a reversed order.
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
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=n-1;i>=0;i--){
            cout<<arr[i]<<" ";
        }
        cout<<'\n';
        
    }
    return 0;
}
