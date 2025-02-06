/*
Question 9 Given an array of integers, find the minimum xor of a pair of elements of the array.
Example:
{2, 3, 7, 6, 4} => 1
{2, 5, 4, 2, 6, 8, 9} => 0
*/
//claim - sort the array in increasing order traverse and find the min xor by updating it consecutively at each step
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr[i]=a;
    }
    int min_xor = 1e9;
    sort(arr.begin(),arr.end());
    for(int i=1;i<n;i++){
        min_xor = min(min_xor,arr[i-1]^arr[i]);
    }
    cout<<min_xor<<'\n';
    return 0;
}
