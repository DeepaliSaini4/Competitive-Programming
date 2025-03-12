/*
Description
A shop makes n types of cookies. Number of cookies of type i is Ci
The shop only sells cookies as a pair. Moreover the two cookies in a pair must be of different types.
Your job is to sell as many pairs as possible and find the minimum number of cookies that remain at the end.
 
Input Format
First line of input contains T, number of test cases.
First line of each test case contains n.
The next line contains n integers, Ci for i from 1 to n.

Output Format
For each test case output one integer: Remaining cookies.

Constraints
T ≤ 10
1 ≤ n ≤ 105
1 ≤ Ci ≤ 109

Sample Input 1
1
3
2 1 3

Sample Output 1
0

Sample Input 2
1
3
3 4 5

Sample Output 2
0
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solver(){
    int n;
    cin>>n;
    int arr[n];
    int sum =0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    sort(arr,arr+n);
    int rem_sum = sum - arr[n-1];
    // two cases of cookies 
    //1. higest cannot be exhausted so ans is reamining after removing from highest
    if(rem_sum<arr[n-1]){
        cout<<arr[n-1]-rem_sum<<'\n';
    }
    //2. Higest can be exhausted then the reamining are paired opimally 
    else{
        cout<<(rem_sum- arr[n-1])%2<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solver();
    }
    return 0;
}
//tc=O(T⋅nlogn) --> sorting
