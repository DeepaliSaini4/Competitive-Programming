/*
Description
Given an array A of size N and a number X. Print the array elements after shifting right the elements X times.
For example: if A=[1,2,3] then after shifting it to the right for 1 time A=[3,1,2].

Note
Note: Solve this problem using function.

Input Format
First line will contain two number N and X.
Second line will contain N numbers.

Output Format
Print the array after shifting right its elements X times.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(x>n)
    x = x%n;
    int idx = n-x;
    if (idx==0){
        //original array needs to printed as it is
        idx = 0;
    }
    for(int i=idx;i<n;i++){
        cout<<arr[i]<<" ";
    }
    if(idx!=0){
        //some remaining part needs to be printed as well
        for(int i=0;i<idx;i++){
            cout<<arr[i]<<" ";
        }
    }

    return 0;
}
