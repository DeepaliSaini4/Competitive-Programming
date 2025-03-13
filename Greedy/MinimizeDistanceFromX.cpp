/*
Description
You are given an array A of n non-negative integers.
Define function F = Summation of |Ai-X|^2 for all i from 1 to n.
Find the minimum value of the function F by choosing an appropriate integer X.

Input Format
First line of input contains T, number of test cases.
First line of each test case contains n .
Second line contains n integers, Ai , the array A.

Output Format
For each test case print the minimum value of F.

Constraints
T ≤ 10
1 ≤ n ≤ 105
0 ≤ Ai ≤ 106

Sample Input 1
1
3
2 2 3

Sample Output 1
1
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solver(){
    
    int n;
    cin>>n;

    int sum=0;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }

    int x = round((double)sum/n);//**rounding off the decimal part to prevent truncation errors

    int func_val =0 ;
    for(int i=0;i<n;i++)func_val += (arr[i] - x)*(arr[i] - x);

    cout<<func_val<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) solver();
    return 0;
}
