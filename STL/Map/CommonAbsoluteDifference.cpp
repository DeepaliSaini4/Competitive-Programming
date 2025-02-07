/*
Description
You are given an array A of N integers and an integer K. Find the number of pairs (i, j) such that i < j and abs(Ai - Aj) = K

Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.


The first line of each test case contains two space-separated integers N K - the length of the array and the required absolute difference.


The second line of each test case contains N space-separated integers.

Output Format
For each test case, print the number of pairs (i, j) such that i < j and abs(Ai - Aj) = K

Constraints
1≤T≤10^5
1≤N≤10^5
1≤Ai≤10^9
1≤K≤10^9
 
It is guaranteed that the sum of N over all test cases does not exceed 10^5.

*/
// Write your code here
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n];
        map<int,int>m;
        for(int i=0;i<n;i++){
            cin>>a[i];
            m[a[i]]++;
        }
        long long count=0;
        for(int i=0;i<n;i++){
            m[a[i]]--;
            int t1=m[a[i]-k];
            int t2=m[a[i]+k];
            count=count+t1+t2;
        }
        cout<<count<<"\n";
    }
    return 0;
}
