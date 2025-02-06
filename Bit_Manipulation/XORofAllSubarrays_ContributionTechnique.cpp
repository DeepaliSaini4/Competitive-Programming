/*
Given an array of integers, find the xor of elements of all the subarrays possible.

Example:

{12,15,6,7,9,14,18} => 17
{2,5,6,8,7,12} => 0
*/
//find the number of times each element will come in the xor calculation 
// for each element find the number of subarrays of whcih it is a part
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        int freq = (i+1)*(n-i); //the given element at the ith index can be the part of how many subarrays
        if(freq%2){
            ans^=arr[i];
        }
    }
    cout<<ans<<'\n';
    return 0;
}
