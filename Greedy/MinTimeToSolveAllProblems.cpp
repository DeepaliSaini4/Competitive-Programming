/*
Description
There are N problems in a contest, and the ith problem has a rating Ri.They are posted in an order top to bottom as given in the input.
Each problem requires at least 1 minute to solve. You also know that if a problem P has a higher rating than a problem just above or just below it, then 
P must take strictly more time to solve than that problem.Find the minimum possible time required to solve all the problems.

Input Format
First line of input contains T, the number of test cases.
First line of each test case contains N.
Second line contains N integers, Ri for i from 1 to N.

Output Format
For each test case, output one integer: The minimum possible time in which all problems could be solved.

Sample Input 1
1
3
2 1 3

Sample Output 1
5
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solver(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    
    int a1[n],a2[n];

    //forward pass - is right neighbor bigger?
    a1[0] = 1;//min amount of time taken to solve a problem
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1])a1[i] = a1[i-1] + 1; //assign one greater than the left neighbor
        else a1[i] = 1;
    }

    //backward pass - is left neighbor bigger?
    a2[n-1] = 1;//min time taken to solve a problem
    for(int i=n-2;i>=0;i--){
        if(arr[i]>arr[i+1])a2[i] = a2[i+1] + 1;
        else a2[i] = 1;
    }

    //formulating final ans
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=max(a1[i],a2[i]);
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solver();
    return 0;
}
